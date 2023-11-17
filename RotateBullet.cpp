#include "RotateBullet.h"

void RotateBullet::Initialize()
{
	info.sizeX = 20;
	info.sizeY = 20;
	bulletSpeed = 5;

	rotAngle = 90;
	rotRange = 30;

	isFire = false;
}

void RotateBullet::Update()
{
	if (!isFire)
	{
		// 가상의 점의 위치를 포신의 끝 부분으로 처음 한 번 설정
		isFire = true;
		rotCenterX = info.posX;
		rotCenterY = info.posY;
	}

	// 가상의 점을 기준으로 실제 총알을 회전 시킴
	info.posX = rotCenterX + cosf(rotAngle * PI / 180) * rotRange;
	info.posY = rotCenterY + -sinf(rotAngle * PI / 180) * rotRange;

	// 발사 시점의 포신 방향대로 가상의 점을 이동시킴
	rotCenterX += cosf(angle * PI / 180) * bulletSpeed;
	rotCenterY += -sinf(angle * PI / 180) * bulletSpeed;

	// 가상의 점을 기준으로 총알이 계속해서 회전할 수 있도록
	// rotAngle에 임의의 각을 계속해서 더함
	rotAngle += 30;
}

void RotateBullet::Render(HDC hdc)
{
	HBRUSH myBrush = CreateSolidBrush(RGB(117, 250, 141));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
}

void RotateBullet::Release()
{
}

RotateBullet::RotateBullet()
{
}

RotateBullet::~RotateBullet()
{
}
