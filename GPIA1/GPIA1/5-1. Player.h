#pragma once
#include <iostream>
using namespace std;

class Player
{
public:
	// ��� �Լ�
	void Attack();
	void Die();
	void HealMe(int value);
public:
	// ��� ����
	int hp;
	int attack;
	int defence;
};

