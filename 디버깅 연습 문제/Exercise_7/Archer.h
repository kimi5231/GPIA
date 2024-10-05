#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer();
	Archer(int hp);
	// Before
	// ~Archer();
	
	// After
	virtual ~Archer();

public:
	class Pet* _pet;
};

