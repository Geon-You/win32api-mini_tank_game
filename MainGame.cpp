#include "MainGame.h"

list<Object*> MainGame::monsters;

void MainGame::Initialize()
{
	srand(GetTickCount64());
	// 전역 윈도우 핸들을 통해 dc를 가져온다
	hdc = GetDC(g_hWnd);

	player = new Player();
	player->Initialize();

	// 메인 게임이 갖는 총알 리스트의 주소를 플레이어 객체에 넘김
	((Player*)player)->SetBulletList(&bullets);

	// 몬스터 생성
	for (int i = 0; i < 15; ++i)
	{
		Object* monster = AbstractFactory<Monster>::CreateObject(rand() % WIN_SIZE_X + 1, rand() % WIN_SIZE_Y + 1);
		monsters.push_back(monster);
	}
}

void MainGame::Update()
{
	player->Update();

	// 총알 업데이트 및 화면 밖으로 나갔을 땐 메모리 해제
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

	// 몬스터 업데이트
	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		(*iter)->Update();
	}

	//// 총알과 몬스터의 충돌을 감지해서 닿았다면 몬스터와 총알 제거(메모리 해제)
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
	// 창 해상도만큼 사각형을 새로 그려, 화면이 지워진 것처럼 보이게 함
	Rectangle(hdc, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);

	player->Render(hdc);

	for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
		(*iter)->Render(hdc);

	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
		(*iter)->Render(hdc);
}

void MainGame::Release()
{
	// 플레이어 객체가 존재한다면 해제
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

	// 가져왔던 dc를 시스템에 반환 (메모리 해제)
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
