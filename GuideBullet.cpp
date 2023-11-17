#include "GuideBullet.h"

void GuideBullet::Initialize()
{
	info.sizeX = 15;
	info.sizeY = 15;
	bulletSpeed = 15;
}

void GuideBullet::Update()
{
	// 가이드 불렛과 가장 가까운 타겟을 찾아야 함 (몬스터들의 정보를 가져와야 함)
	Object* target = GetTarget();

	if (target == nullptr)
		return;

	// 타겟을 찾았으면 해당 타겟쪽을 향하는 각도를 구함
	auto targetAngle = MathUtil::GetAngle(target, this); // 타겟까지의 각도(방향)

	// 구한 각도(방향)쪽으로 이동
	info.posX += cosf(targetAngle * PI / 180) * bulletSpeed;
	info.posY += -sinf(targetAngle * PI / 180) * bulletSpeed;
}

void GuideBullet::Render(HDC hdc)
{
	HBRUSH myBrush = CreateSolidBrush(RGB(115, 43, 245));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
}

void GuideBullet::Release()
{
}

Object* GuideBullet::GetTarget()
{
	// 최소거리를 담아둘 변수
	float minDistance = 1000.0f;
	// 최소거리를 갖는 개체를 담아둘 변수
	Object* target = nullptr;

	auto monsters = MainGame::monsters;
	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		// 가이드 불렛과 몬스터 개체 사이의 거리를 구함
		float distance = MathUtil::GetDistance(this, (*iter));

		// 이전 연산에서 구했던 최소 거리보다 현재 구한 거리가 더 짧다면
		if (distance < minDistance)
		{
			// 최소 거리를 갱신
			minDistance = distance;
			target = (*iter);
		}
	}

	return target;
}

GuideBullet::GuideBullet()
{
}

GuideBullet::~GuideBullet()
{
}
