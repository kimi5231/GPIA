#pragma once

class Actor;
class Creature;
class UI;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);
	
	Creature* GetCreatureAt(Vec2Int cellPos);

public:
	vector<Actor*> _actors[LAYER_MAXCOUNT];
	vector<UI*> _uis;
};

