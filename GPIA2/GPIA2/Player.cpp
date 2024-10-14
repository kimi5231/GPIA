#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "Bullet.h"
#include "LineMesh.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// 거리 = 시간 * 속도

	if (!_playerTurn)
		return;

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
		_dir = Dir::Left;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
		_dir = Dir::Right;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::W))
	{
		//_pos.y -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::S))
	{
		//_pos.y += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::Q))
	{
	
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::E))
	{
	
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::SpaceBar))
	{
	
	}
}

void Player::Render(HDC hdc)
{
	if (_dir == Dir::Left)
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
		if (mesh)
		{
			mesh->Render(hdc, _pos, 0.5f, 0.5f);
		}
	}
	else
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
		if (mesh)
		{
			mesh->Render(hdc, _pos, -0.5f, 0.5f);
		}
	}

	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, pen);

	//Utils::DrawLine(hdc, _pos, GetFirePos());

	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);
}

wstring Player::GetMeshKey()
{
	if (_playerType == PlayerType::MissileTank)
		return L"MissileTank";
	
	return L"CanonTank";
}
