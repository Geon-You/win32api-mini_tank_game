#pragma once
#include "Object.h"
#include "Bullet.h"
#include "AbstractFactory.h"
#include "NormalBullet.h"
#include "RotateBullet.h"
#include "GuideBullet.h"

class Player :
    public Object
{
public:
    // Object을(를) 통해 상속됨
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

private:
    int speed; // 움직이는 속도
    list<Object*>* bulletListAddress; // 메인 게임에 있는 총알 리스트의 주소를 갖는 필드
    // 포신의 길이
    float gunBarrelLength;
    // 포신 회전 시, 사용할 각
    float gunBarrelAngle;

public:
    void SetBulletList(list<Object*>* listAddress)
    {
        bulletListAddress = listAddress;
    }

private:
    template<typename T>
    Object* CreateBullet();

public:
    Player();
    virtual ~Player();
};
