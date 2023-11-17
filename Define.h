#pragma once
#include "framework.h"

#define WIN_SIZE_X 1600
#define WIN_SIZE_Y 950

#define PI 3.14159265358979323

extern HWND g_hWnd;

// Ư�� ��ü�� �׸� ��, ��ġ�� ����� �ʿ�
// �׷� �� ������ ��ġ�� ����� �Ź� ���� �����ϱ� �������ϱ�
// ���� ���Ǵ� �����͸� ����ü�� ����� ó��
typedef struct tagInfo
{
	int posX;
	int posY;
	int sizeX;
	int sizeY;
}INFO;