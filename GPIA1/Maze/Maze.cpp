#include "pch.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<uint32>(time(nullptr)));

	while (true)
	{
		board.Render();
	}
}