#pragma once
#include "Define.h"

// ��� ���� ��ü�� ���̽��� �� �߻� Ŭ����
class Object abstract
{
protected:
	// ���� ��ü���� ���������� ���� �����͵��� ����
	INFO info;

public:
	INFO GetInfo() { return info; }
	void SetPos(int x, int y) { info.posX = x; info.posY = y; }

public:
	virtual void Initialize() abstract; // ��� ��ü�� ���� ��, �ʱ�ȭ ������ ���´�
	virtual void Update() abstract; // ��� ��ü�� Ư�� ������ �Ѵ�.
	virtual void Render(HDC hdc) abstract; // ��� ��ü�� ȭ��(hdc)�� �׷��� �� �ִ�.
	virtual void Release() abstract; // ��� ��ü�� �ı��� ��, �����޸𸮸� ��� ���̶�� �����Ѵ�.

public:
	Object();
	// Ŭ���� ��Ӱ��迡�� �������� �̿� ��, �Ҹ��ڸ� ���� �Ҹ��ڷ� ������ �ʴ´ٸ�
	// ���������� �Ҹ��ڰ� ȣ����� ����
	virtual ~Object();
};

