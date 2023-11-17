#pragma once
#include "Object.h"
#include "WindowsProject1.h"

class Bullet abstract:
    public Object
{
protected:
    // degree : �Ϲ������� �츮�� ����ϴ� ���� (��)
    // radian : ȣ����(ȣ�� ������ ������ �̿�), ��ǻ�Ͱ� ������ �����ϴ� ����
    float angle; // �Ѿ��� �߻�� ������ ���� �ʵ�, degree ���·� ���� �Է�
    int bulletSpeed;

public:
    void SetAngle(float angle) { this->angle = angle; }

public:
    // Object��(��) ���� ��ӵ�
    void Initialize() abstract;
    void Update() abstract;
    void Render(HDC hdc) abstract;
    void Release() abstract;

public:
    Bullet();
    virtual ~Bullet();
};

