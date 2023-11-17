#include "Monster.h"

void Monster::Initialize()
{
	info.sizeX = 50;
	info.sizeY = 50;

	monsterSpeed = 1;
}

void Monster::Update()
{
	//float MonsterToPlayerAngle = MathUtil::GetAngle(, this); // 타겟까지의 각도(방향)
	//info.posX += cosf(MonsterToPlayerAngle * PI / 180) * monsterSpeed;
	//info.posY += -sinf(MonsterToPlayerAngle * PI / 180) * monsterSpeed;

	//// 총알과 몬스터의 충돌을 감지해서 닿았다면 몬스터와 총알 제거(메모리 해제)
	//auto bullets = MainGame::bullets;
	//for (auto iter = bullets.begin(); iter != bullets.end(); ++iter)
	//{
	//	if (MathUtil::OnCollision(this, *iter))
	//	{
	//		delete* iter;
	//		*iter = nullptr;
	//		iter = bullets.erase(iter);
	//	}
	//	else
	//	{
	//		++iter;
	//	}
	//}
}

void Monster::Render(HDC hdc)
{
	HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);
	Ellipse(hdc, info.posX - info.sizeX, info.posY - info.sizeY,
		info.posX + info.sizeX, info.posY + info.sizeY);
	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
}

void Monster::Release()
{
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
