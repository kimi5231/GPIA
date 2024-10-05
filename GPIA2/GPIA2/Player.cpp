#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "Missile.h"
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

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::W))
	{
		_pos.y -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::S))
	{
		_pos.y += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::SpaceBar))
	{
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	//Utils::DrawCircle(hdc, _pos, 50);
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player.txt");
	if (mesh)
	{
		mesh->Render(hdc, _pos);
	}
}
