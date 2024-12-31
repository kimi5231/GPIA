#pragma once
#include "Projectile.h"

class Flipbook;

class Arrow: public Projectile
{
	using Super = Projectile;
public:
	Arrow();
	virtual ~Arrow() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

private:
	virtual void TickIdle() override;
	virtual void TickMove() override;
	virtual void UpdateAnimation();

private:
	Flipbook* _flipbookMove[4]{};
};

