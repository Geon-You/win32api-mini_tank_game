#pragma once
#include "Bullet.h"
#include "MainGame.h"

class GuideBullet :
    public Bullet
{
public:
    // Bullet��(��) ���� ��ӵ�
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

private:
    Object* GetTarget();

public:
    GuideBullet();
    virtual ~GuideBullet();
};

