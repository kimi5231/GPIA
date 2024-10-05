#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp);
	~Knight();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

public:
	// Before
	// int _hp; 
	
	// After
	long long _hp;
	int _attack;
};

