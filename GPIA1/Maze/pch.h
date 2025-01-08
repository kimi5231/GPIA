#pragma once

#include "Types.h"
#include <windows.h>
#include <iostream>

using namespace std;

struct Pos
{
	Pos() {}
	Pos(int32 x, int32 y) : x(x), y(y) {}

	bool operator==(const Pos& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Pos& other)
	{
		return !(*this == other);
	}

	Pos operator+(const Pos& other)
	{
		Pos ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Pos operator+=(const Pos& other)
	{
		Pos ret;
		x += other.x;
		y += other.y;
		return *this;
	}

	int x = 0;
	int y = 0;
};

enum Dir
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4
};