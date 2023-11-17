#pragma once
#include "Object.h"
#include "MainGame.h"
#include "AbstractFactory.h"

class Monster :
    public Object
{
public:
    // Object을(를) 통해 상속됨
    void Initialize() override;
    void Update() override;
    void Render(HDC hdc) override;
    void Release() override;

private:
    int monsterSpeed; // 플레이어를 따라다닐 속도

public:
    Monster();
    virtual ~Monster();
};
