#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	virtual ~Bullet() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	Pos GetFirePos();
};

