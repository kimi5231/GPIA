#pragma once
#include <iostream>
using namespace std;

class Player
{
public:
	// ¸â¹ö ÇÔ¼ö
	void Attack();
	void Die();
	void HealMe(int value);
public:
	// ¸â¹ö º¯¼ö
	int hp;
	int attack;
	int defence;
};

