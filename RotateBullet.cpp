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
		// ������ ���� ��ġ�� ������ �� �κ����� ó�� �� �� ����
		isFire = true;
		rotCenterX = info.posX;
		rotCenterY = info.posY;
	}

	// ������ ���� �������� ���� �Ѿ��� ȸ�� ��Ŵ
	info.posX = rotCenterX + cosf(rotAngle * PI / 180) * rotRange;
	info.posY = rotCenterY + -sinf(rotAngle * PI / 180) * rotRange;

	// �߻� ������ ���� ������ ������ ���� �̵���Ŵ
	rotCenterX += cosf(angle * PI / 180) * bulletSpeed;
	rotCenterY += -sinf(angle * PI / 180) * bulletSpeed;

	// ������ ���� �������� �Ѿ��� ����ؼ� ȸ���� �� �ֵ���
	// rotAngle�� ������ ���� ����ؼ� ����
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
