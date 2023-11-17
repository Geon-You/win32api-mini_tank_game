#pragma once
#include "Object.h"
#include "WindowsProject1.h"

class Bullet abstract:
    public Object
{
protected:
    // degree : 일반적으로 우리가 사용하는 각도 (도)
    // radian : 호도법(호의 길이의 비율을 이용), 컴퓨터가 각도를 연산하는 단위
    float angle; // 총알이 발사될 각도를 갖는 필드, degree 형태로 값을 입력
    int bulletSpeed;

public:
    void SetAngle(float angle) { this->angle = angle; }

public:
    // Object을(를) 통해 상속됨
    void Initialize() abstract;
    void Update() abstract;
    void Render(HDC hdc) abstract;
    void Release() abstract;

public:
    Bullet();
    virtual ~Bullet();
};

