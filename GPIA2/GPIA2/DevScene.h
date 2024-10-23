#pragma once
#include "Scene.h"

class Actor;
class GameObject;

class DevScene : public Scene
{
public:
	DevScene();
	virtual ~DevScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	vector<Actor*> _actors;
};