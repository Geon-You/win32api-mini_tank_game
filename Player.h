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
    // Object��(��) ���� ��ӵ�
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

private:
    int speed; // �����̴� �ӵ�
    list<Object*>* bulletListAddress; // ���� ���ӿ� �ִ� �Ѿ� ����Ʈ�� �ּҸ� ���� �ʵ�
    // ������ ����
    float gunBarrelLength;
    // ���� ȸ�� ��, ����� ��
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
