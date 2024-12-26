#include "pch.h"
#include "GameObject.h"
#include "DevScene.h"
#include "SceneManager.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::BeginPlay()
{
	Super::BeginPlay();

	SetState(ObjectState::Move);
	SetState(ObjectState::Idle);
}

void GameObject::Tick()
{
	Super::Tick();

	switch (_state)
	{
	case ObjectState::Idle:
		TickIdle();
		break;
	case ObjectState::Move:
		TickMove();
		break;
	case ObjectState::Skill:
		TickSkill();
		break;
	}
}

void GameObject::Render(HDC hdc)
{
	Super::Render(hdc);

}


void GameObject::SetState(ObjectState state)
{
	if (_state == state)
		return;

	_state = state;
	UpdateAnimation();
}

void GameObject::SetDir(Dir dir)
{
	_dir = dir;
	UpdateAnimation();
}

bool GameObject::HasReachedDest()
{
	Vec2 dir = (_destPos - _pos);
	return (dir.Length() < 10.f);
}

bool GameObject::CanGo(Vec2Int cellPos)
{
	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
		return false;

	return scene->CanGo(cellPos);
}

void GameObject::SetCellPos(Vec2Int cellPos, bool teleport)
{
	_cellPos = cellPos;

	DevScene* scene = dynamic_cast<DevScene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
	if (scene == nullptr)
		return;

	_destPos = scene->ConvertPos(cellPos);

	if (teleport)
		_pos = _destPos;
}

Vec2Int GameObject::GetFrontCellPos()
{
	switch (_dir)
	{
	case DIR_DOWN:
		return _cellPos + Vec2Int{ 0, 1 };
		break;
	case DIR_LEFT:
		return _cellPos + Vec2Int{ -1, 0 };
		break;
	case DIR_RIGHT:
		return _cellPos + Vec2Int{ 1, 0 };
		break;
	case DIR_UP:
		return _cellPos + Vec2Int{ 0, -1 };
		break;
	}

	return _cellPos;
}
