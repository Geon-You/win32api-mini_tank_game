#pragma once
#include "Bullet.h"
class RotateBullet :
    public Bullet
{
private:
    // �Ѿ��� ȸ���� �� ���� ������ �� x, y
    float rotCenterX;
    float rotCenterY;
    // �Ѿ��� ȸ���� �� ���� ��
    float rotAngle;
    // �Ѿ��� ȸ���ϴ� �ݰ�
    float rotRange;
    bool isFire;

public:
    // Bullet��(��) ���� ��ӵ�
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

public:
    RotateBullet();
    virtual ~RotateBullet();
};

