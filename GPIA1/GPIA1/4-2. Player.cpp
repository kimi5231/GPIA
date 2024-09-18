#include "4-2. Player.h"
#include "4-2. Map.h"
#include "4-2. Helper.h"

bool canMove = true;

int GPlayerX = 2;
int GPlayerY = 2;

void MovePlayer1D(int x, int y)
{
	// ���� üũ
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;

	// �� üũ
	int index = y * MAP_SIZE + x;
	if (GMap1D[index] == 1)
		return;

	// ���� ��ġ ����
	{
		int index = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[index] = 0;
	}

	// �� ��ġ �̵�
	{
		GPlayerX = x;
		GPlayerY = y;
		int index = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[index] = 2;
	}
}

void MovePlayer2D(int x, int y)
{
	// ���� üũ
	if (x < 0 || x >= MAP_SIZE)
		return;
	if (y < 0 || y >= MAP_SIZE)
		return;

	// �� üũ
	if (GMap2D[y][x] == 1)
		return;

	// ���� ��ġ ����
	GMap2D[GPlayerY][GPlayerX] = 0;

	// �� ��ġ �̵�
	GPlayerX = x;
	GPlayerY = y;
	GMap2D[GPlayerY][GPlayerX] = 2;
}

void HandleMove1D()
{
	// Ű���带 ���� ������, �������� ������ �� �ִ�
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	if (canMove == false)
		return;

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer1D(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer1D(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer1D(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer1D(GPlayerX, GPlayerY + 1);
		break;
	}
}

void HandleMove2D()
{
	// Ű���带 ���� ������, �������� ������ �� �ִ�
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	if (canMove == false)
		return;

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer2D(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer2D(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer2D(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer2D(GPlayerX, GPlayerY + 1);
		break;
	}
}