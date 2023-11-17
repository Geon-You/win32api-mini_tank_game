#include "MainGame.h"

list<Object*> MainGame::monsters;

void MainGame::Initialize()
{
	srand(GetTickCount64());
	// ���� ������ �ڵ��� ���� dc�� �����´�
	hdc = GetDC(g_hWnd);

	player = new Player();
	player->Initialize();

	// ���� ������ ���� �Ѿ� ����Ʈ�� �ּҸ� �÷��̾� ��ü�� �ѱ�
	((Player*)player)->SetBulletList(&bullets);

	// ���� ����
	for (int i = 0; i < 15; ++i)
	{
		Object* monster = AbstractFactory<Monster>::CreateObject(rand() % WIN_SIZE_X + 1, rand() % WIN_SIZE_Y + 1);
		monsters.push_back(monster);
	}
}

void MainGame::Update()
{
	player->Update();

	// �Ѿ� ������Ʈ �� ȭ�� ������ ������ �� �޸� ����
	for (auto iter = bullets.begin(); iter != bullets.end();)
	{
		(*iter)->Update();

		if ((*iter)->GetInfo().posY < 15 || (*iter)->GetInfo().posY > WIN_SIZE_Y - 70 || 
			(*iter)->GetInfo().posX < 15 || (*iter)->GetInfo().posX > WIN_SIZE_X - 30)
		{
			delete* iter;
			*iter = nullptr;
			iter = bullets.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	// ���� ������Ʈ
	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		(*iter)->Update();
	}

	//// �Ѿ˰� ������ �浹�� �����ؼ� ��Ҵٸ� ���Ϳ� �Ѿ� ����(�޸� ����)
	//auto monsters = MainGame::monsters;
	//for (auto iter = monsters.begin(); iter != monsters.end();)
	//{
	//	for (auto iter2 = bullets.begin(); iter != bullets.end(); ++iter)
	//	{
	//		if (MathUtil::OnCollision((*iter), (*iter2)))
	//		{
	//			delete* iter;
	//			*iter = nullptr;
	//			iter = monsters.erase(iter);
	//		}
	//		else
	//		{
	//			++iter;
	//		}
	//	}
	//}
}

void MainGame::Render()
{
	// â �ػ󵵸�ŭ �簢���� ���� �׷�, ȭ���� ������ ��ó�� ���̰� ��
	Rectangle(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);

	player->Render(hdc);

	for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
		(*iter)->Render(hdc);

	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
		(*iter)->Render(hdc);
}

void MainGame::Release()
{
	// �÷��̾� ��ü�� �����Ѵٸ� ����
	if (player)
	{
		delete player;
		player = nullptr;
	}

	for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
	{
		if (*iter)
		{
			delete* iter;
			*iter = nullptr;
		}
	}

	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		if (*iter)
		{
			delete* iter;
			*iter = nullptr;
		}
	}

	// �����Դ� dc�� �ý��ۿ� ��ȯ (�޸� ����)
	ReleaseDC(g_hWnd, hdc);

	bullets.clear();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
