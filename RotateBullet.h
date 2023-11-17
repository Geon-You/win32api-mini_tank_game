#pragma once
#include "Bullet.h"
class RotateBullet :
    public Bullet
{
private:
    // 총알이 회전할 때 쓰일 가상의 점 x, y
    float rotCenterX;
    float rotCenterY;
    // 총알이 회전할 때 쓰일 각
    float rotAngle;
    // 총알이 회전하는 반경
    float rotRange;
    bool isFire;

public:
    // Bullet을(를) 통해 상속됨
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

public:
    RotateBullet();
    virtual ~RotateBullet();
};

