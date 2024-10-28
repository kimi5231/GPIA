#pragma once
#include "FilpbookActor.h"

class Collider;
class BoxCollider;

class Player : public FilpbookActor
{
	using Super = FilpbookActor;
public:
	Player();
	virtual ~Player() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;

private:
	void TickGravity();
	void AdjustCollistionPos(BoxCollider* b1, BoxCollider* b2);

private:
	Flipbook* _flipbookUp = nullptr;
	Flipbook* _flipbookDown = nullptr;
	Flipbook* _flipbookLeft = nullptr;
	Flipbook* _flipbookRight = nullptr;
};

