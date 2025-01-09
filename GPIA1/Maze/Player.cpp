#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	CalculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지
	Pos dest = _board->GetExitPos();

	/*for (int i = 0; i < 10; ++i)
	{
		pos += Pos(1, 0);
		_path.push_back(pos);
	}*/

	Pos front[4] = {
		Pos(-1, 0),
		Pos(0, -1),
		Pos(1, 0),
		Pos(0, 1),
	};

	//Pos next = pos + front[_dir];

	// 오른쪽 방향 90도 회전
	//_dir = (_dir - 1) % DIR_COUNT;
	// 왼쪽 방향 90도 회전
	//_dir = (_dir + 1) % DIR_COUNT;

	while (pos != dest)
	{
		int32 newDir = (_dir - 1) % DIR_COUNT;

		if (CanGo(pos + front[newDir]))
		{
			_path.push_back(pos + front[newDir]);
			pos += front[newDir];
		}
		else if (CanGo(pos + front[_dir]))
		{
			_path.push_back(pos + front[_dir]);
			pos += front[_dir];
		}
		else
		{
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}
}
