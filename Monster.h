#pragma once
#include "Object.h"
#include "MainGame.h"
#include "AbstractFactory.h"

class Monster :
    public Object
{
public:
    // Object��(��) ���� ��ӵ�
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

private:
    int monsterSpeed; // �÷��̾ ����ٴ� �ӵ�

public:
    Monster();
    virtual ~Monster();
};
