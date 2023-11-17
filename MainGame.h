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
	HDC hdc; // ���� �� ��ü�� �׸� �� ���� hdc(��ȭ��)
	Object* player; // �÷��̾� ��ü
	Object* monster; // ���� ��ü
	list<Object*> bullets; // ������ �Ѿ˵��� ���� ����Ʈ

public:
	static list<Object*> monsters; // ������ ���͵��� ���� ����Ʈ

public:
	void Initialize(); // �ʱ�ȭ
	void Update(); // ���� �� ����
	void Render(); // �׸���
	void Release(); // �޸� ����

public:
	MainGame();
	~MainGame();
};

