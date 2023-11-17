#include "NormalBullet.h"

void NormalBullet::Initialize()
{
	info.sizeX = 10;
	info.sizeY = 10;
	bulletSpeed = 8;
}

void NormalBullet::Update()
{
	// degree to radian : angle * PI / 180
	info.posX += cosf(angle * PI / 180) * bulletSpeed;
	info.posY += -sinf(angle * PI / 180) * bulletSpeed;
}

void NormalBullet::Render(HDC hdc)
{
	HBRUSH myBrush = CreateSolidBrush(RGB(255, 242, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
}

void NormalBullet::Release()
{
}

NormalBullet::NormalBullet()
{
}

NormalBullet::~NormalBullet()
{
}
