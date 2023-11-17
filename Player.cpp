#include "Player.h"

// 1. up, down 키를 탱크의 전진, 후진으로 변경
// 탱크의 전진, 후진의 방향은 포신의 방향으로 결정
// 2. 1의 작업으로 인해 전진, 후진만으로 모든 방향에 대해 이동이 가능해지므로
// 왼쪽, 오른쪽 키를 포신 회전크로 변경 

void Player::Initialize()
{
	// 절반 사이즈로 사용 됨
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
		//// 생성한 총알의 초기 위치를 플레이어의 위치로 설정
		//bullet->SetPos(info.posX, info.posY);

		// 총알 리스트에 생성한 총알 객체를 담음
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
	// 탱크 몸통
	HBRUSH myBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);

	// 탱크 포신
	// 직선 그리시 시작할 부분(시작점)을 지정
	MoveToEx(hdc, info.posX, info.posY, NULL);

	int gbPosX = info.posX + cosf(gunBarrelAngle * PI / 180) * gunBarrelLength;
	int gbPosY = info.posY + -sinf(gunBarrelAngle * PI / 180) * gunBarrelLength;

	// 직선의 끝점을 지정
	LineTo(hdc, gbPosX, gbPosY);
}

void Player::Release()
{
}

template<typename T>
inline Object* Player::CreateBullet()
{
	// 포신에서부터 총알이 생성되도록 포신의 끝 부분 위치를 구한다.
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
