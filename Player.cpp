#include "Player.h"

// 1. up, down Ű�� ��ũ�� ����, �������� ����
// ��ũ�� ����, ������ ������ ������ �������� ����
// 2. 1�� �۾����� ���� ����, ���������� ��� ���⿡ ���� �̵��� ���������Ƿ�
// ����, ������ Ű�� ���� ȸ��ũ�� ���� 

void Player::Initialize()
{
	// ���� ������� ��� ��
	info.sizeX = 30;
	info.sizeY = 30;
	info.posX = WIN_SIZE_X * 0.5f;
	info.posY = WIN_SIZE_Y * 0.5f;

	speed = 3;

	gunBarrelLength = 100;
	gunBarrelAngle = 0;
}

void Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		info.posX += cosf(gunBarrelAngle * PI / 180) * speed;
		info.posY += -sinf(gunBarrelAngle * PI / 180) * speed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		info.posX += -cosf(gunBarrelAngle * PI / 180) * speed;
		info.posY += sinf(gunBarrelAngle * PI / 180) * speed;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		gunBarrelAngle += 5;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		gunBarrelAngle -= 5;
	}

	if (GetAsyncKeyState('Q'))
	{
		//Object* bullet = new Bullet();
		//bullet->Initialize();
		//// ������ �Ѿ��� �ʱ� ��ġ�� �÷��̾��� ��ġ�� ����
		//bullet->SetPos(info.posX, info.posY);

		// �Ѿ� ����Ʈ�� ������ �Ѿ� ��ü�� ����
		bulletListAddress->push_back(CreateBullet<NormalBullet>());
	}

	if (GetAsyncKeyState('W'))
	{
		bulletListAddress->push_back(CreateBullet<RotateBullet>());
	}

	if (GetAsyncKeyState('E'))
	{
		bulletListAddress->push_back(CreateBullet<GuideBullet>());
	}
}

void Player::Render(HDC hdc)
{
	// ��ũ ����
	HBRUSH myBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);

	// ��ũ ����
	// ���� �׸��� ������ �κ�(������)�� ����
	MoveToEx(hdc, info.posX, info.posY, NULL);

	int gbPosX = info.posX + cosf(gunBarrelAngle * PI / 180) * gunBarrelLength;
	int gbPosY = info.posY + -sinf(gunBarrelAngle * PI / 180) * gunBarrelLength;

	// ������ ������ ����
	LineTo(hdc, gbPosX, gbPosY);
}

void Player::Release()
{
}

template<typename T>
inline Object* Player::CreateBullet()
{
	// ���ſ������� �Ѿ��� �����ǵ��� ������ �� �κ� ��ġ�� ���Ѵ�.
	float x = info.posX + cosf(gunBarrelAngle * PI / 180) * gunBarrelLength;
	float y = info.posY + -sinf(gunBarrelAngle * PI / 180) * gunBarrelLength;

	Object* bullet = AbstractFactory<T>::CreateObject(x, y);
	((Bullet*)bullet)->SetAngle(gunBarrelAngle);

	return bullet;
}

Player::Player()
{
}

Player::~Player()
{
}
