#pragma once
#include "Object.h"

class MathUtil
{
public:
	// �Ķ���ͷ� ���� �� ��ü ������ �Ÿ��� ���� ��, ��ȯ�ϴ� ���� �޼���
	static float GetDistance(Object* a, Object* b)
	{
		// �浹�� �����ϰ����ϴ� �� ��ü ������ �Ÿ��� ���Ѵ�.
		// �� ��ü ������ x�������� �Ÿ�
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// �� ��ü ������ y�������� �Ÿ�
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// ���� x, y ���� �Ÿ��� �ϳ��� �����ͷ� ǥ�� (���� �Ÿ��� ����)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		return distance;
	}

	// �Ķ���ͷ� ���� �� ��ü ������ ������ ���� ��, ��ȯ�ϴ� ���� �޼���
	static float GetAngle(Object* a, Object* b)
	{
		// �浹�� �����ϰ����ϴ� �� ��ü ������ �Ÿ��� ���Ѵ�.
		// �� ��ü ������ x�������� �Ÿ�
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// �� ��ü ������ y�������� �Ÿ�
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// ���� x, y ���� �Ÿ��� �ϳ��� �����ͷ� ǥ�� (���� �Ÿ��� ����)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		// ��ũ �ڻ��� (�غ� / ����) -> ���� �� ��Ÿ�� ����
		float angle = acosf(distanceX / distance) * 180 / PI;

		// ��ũ �ڻ����� ���� ���� ������ 180���� �������� �ۿ� ǥ���� �ȵ� (�ٲ� ���ǿ��� ����)
		// 180�� �̻��� ������ ǥ���� �� �ֵ��� ����� ��
		if (a->GetInfo().posY > b->GetInfo().posY)
		{
			angle = 360 - angle;
		}

		return angle;
	}

	// static�� ������ ���� �޼���, ���� �޼���� �ν��Ͻ� ���� ����� ����
	// Ŭ���� ��ü�� ���ԵǹǷ�
	// �Ķ���ͷ� ���� 2���� ������Ʈ�� �浹�� ����
	static bool OnCollision(Object* a, Object* b)
	{
		// �浹 üũ�� �ϰ��� �ϴ� �� ���� �������� ����
		// -> �� �� ������ �Ÿ��� �� ���� �������� ���� ������ �۴ٸ� �浹�ߴٰ� ó��
		int sum = a->GetInfo().sizeX + b->GetInfo().sizeX;

		// �浹�� �����ϰ����ϴ� �� ��ü ������ �Ÿ��� ���Ѵ�.
		// �� ��ü ������ x�������� �Ÿ�
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// �� ��ü ������ y�������� �Ÿ�
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// ���� x, y ���� �Ÿ��� �ϳ��� �����ͷ� ǥ�� (���� �Ÿ��� ����)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		// �� ���� �������� ���� ���� �����Ÿ����� ũ�ٸ� �浹�ߴٴ� ��
		return sum > distance;
	}
};