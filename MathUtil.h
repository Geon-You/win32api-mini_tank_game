#pragma once
#include "Object.h"

class MathUtil
{
public:
	// 파라미터로 받은 두 객체 사이의 거리를 구한 후, 반환하는 정적 메서드
	static float GetDistance(Object* a, Object* b)
	{
		// 충돌을 감지하고자하는 두 객체 사이의 거리를 구한다.
		// 두 객체 사이의 x축으로의 거리
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// 두 객체 사이의 y축으로의 거리
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// 구한 x, y 축의 거리를 하나의 데이터로 표현 (직선 거리를 구함)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		return distance;
	}

	// 파라미터로 받은 두 객체 사이의 각도를 구한 후, 반환하는 정적 메서드
	static float GetAngle(Object* a, Object* b)
	{
		// 충돌을 감지하고자하는 두 객체 사이의 거리를 구한다.
		// 두 객체 사이의 x축으로의 거리
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// 두 객체 사이의 y축으로의 거리
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// 구한 x, y 축의 거리를 하나의 데이터로 표현 (직선 거리를 구함)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		// 아크 코사인 (밑변 / 빗변) -> 끼인 각 세타를 구함
		float angle = acosf(distanceX / distance) * 180 / PI;

		// 아크 코사인을 통해 구한 각도가 180도의 범위까지 밖에 표현이 안됨 (바뀐 정의역에 의해)
		// 180도 이상의 각도도 표현할 수 있도록 해줘야 함
		if (a->GetInfo().posY > b->GetInfo().posY)
		{
			angle = 360 - angle;
		}

		return angle;
	}

	// static이 붙으면 정적 메서드, 정적 메서드는 인스턴스 없이 사용이 가능
	// 클래스 자체에 포함되므로
	// 파라미터로 받은 2개의 오브젝트의 충돌을 감지
	static bool OnCollision(Object* a, Object* b)
	{
		// 충돌 체크를 하고자 하는 두 원의 반지름을 더함
		// -> 두 원 사이의 거리가 두 원의 반지름을 더한 값보다 작다면 충돌했다고 처리
		int sum = a->GetInfo().sizeX + b->GetInfo().sizeX;

		// 충돌을 감지하고자하는 두 객체 사이의 거리를 구한다.
		// 두 객체 사이의 x축으로의 거리
		int distanceX = a->GetInfo().posX - b->GetInfo().posX;
		// 두 객체 사이의 y축으로의 거리
		int distanceY = a->GetInfo().posY - b->GetInfo().posY;

		// 구한 x, y 축의 거리를 하나의 데이터로 표현 (직선 거리를 구함)
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		// 두 원의 반지름을 더한 값이 직선거리보다 크다면 충돌했다는 뜻
		return sum > distance;
	}
};