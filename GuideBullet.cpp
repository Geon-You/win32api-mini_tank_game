#include "GuideBullet.h"

void GuideBullet::Initialize()
{
	info.sizeX = 15;
	info.sizeY = 15;
	bulletSpeed = 15;
}

void GuideBullet::Update()
{
	// ���̵� �ҷ��� ���� ����� Ÿ���� ã�ƾ� �� (���͵��� ������ �����;� ��)
	Object* target = GetTarget();

	if (target == nullptr)
		return;

	// Ÿ���� ã������ �ش� Ÿ������ ���ϴ� ������ ����
	auto targetAngle = MathUtil::GetAngle(target, this); // Ÿ�ٱ����� ����(����)

	// ���� ����(����)������ �̵�
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
	// �ּҰŸ��� ��Ƶ� ����
	float minDistance = 1000.0f;
	// �ּҰŸ��� ���� ��ü�� ��Ƶ� ����
	Object* target = nullptr;

	auto monsters = MainGame::monsters;
	for (auto iter = monsters.begin(); iter != monsters.end(); ++iter)
	{
		// ���̵� �ҷ��� ���� ��ü ������ �Ÿ��� ����
		float distance = MathUtil::GetDistance(this, (*iter));

		// ���� ���꿡�� ���ߴ� �ּ� �Ÿ����� ���� ���� �Ÿ��� �� ª�ٸ�
		if (distance < minDistance)
		{
			// �ּ� �Ÿ��� ����
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
