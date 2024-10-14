#include "pch.h"
#include "FortressScene.h"
#include "UIManager.h"
#include "Player.h";
#include "LineMesh.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"

FortressScene::FortressScene()
{
}

FortressScene::~FortressScene()
{
}

void FortressScene::Init()
{
	GET_SINGLE(UIManager)->Init();

	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPlayerType(PlayerType::MissileTank);
		player->SetPlayerId(0);

		GET_SINGLE(ObjectManager)->Add(player);

		player->SetPos(Vector{ 100, 400 });
		player->SetPlayerTurn(true);
	}

	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPlayerType(PlayerType::CanonTank);
		player->SetPlayerId(1);

		GET_SINGLE(ObjectManager)->Add(player);

		player->SetPos(Vector{ 700, 400 });
		player->SetPlayerTurn(false);
	}
	
}

void FortressScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
		object->Update();
}

void FortressScene::Render(HDC hdc)
{
	GET_SINGLE(UIManager)->Render(hdc);

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
		object->Render(hdc);
}
