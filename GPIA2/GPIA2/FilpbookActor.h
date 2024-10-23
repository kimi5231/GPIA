#pragma once
#include "Actor.h"

class Flipbook;

class FilpbookActor : public Actor
{
	using Super = Actor;
public:
	FilpbookActor();
	virtual ~FilpbookActor() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	void SetFlipbook(Flipbook* flipbook);
	void Reset();

protected:
	Flipbook* _flipbook = nullptr;
	float _sumTime = 0.f;
	int32 _idx = 0;
};