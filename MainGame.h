#pragma once
#include "Define.h"
#include "Player.h"
#include "Monster.h"
#include "MathUtil.h"
#include "Bullet.h"

class Object;

class MainGame
{
private:
	HDC hdc; // 게임 내 객체를 그릴 때 사용될 hdc(도화지)
	Object* player; // 플레이어 객체
	Object* monster; // 몬스터 객체
	list<Object*> bullets; // 생성된 총알들을 담을 리스트

public:
	static list<Object*> monsters; // 생성된 몬스터들을 담을 리스트

public:
	void Initialize(); // 초기화
	void Update(); // 게임 내 연산
	void Render(); // 그리기
	void Release(); // 메모리 해제

public:
	MainGame();
	~MainGame();
};

