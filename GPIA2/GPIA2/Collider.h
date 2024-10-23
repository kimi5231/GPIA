#pragma once
#include "Component.h"

class BoxCollider;
class SphereCollider;

class Collider : public Component
{
public:
	Collider(ColliderType colliderType);
	virtual ~Collider() override;

	virtual void BeginPlay() override;
	virtual void TickComponent() override;
	virtual void Render(HDC hdc) override;

	virtual bool CheckCollision(Collider* other);

	ColliderType GetColliderType() { return _colliderType; }
	void SetShowDebug(bool show) { _showDedug = show; }

public:
	static bool CheckToCollisionBox2Box(BoxCollider* b1, BoxCollider* b2);
	static bool CheckToCollisionSphere2Box(SphereCollider* s1, BoxCollider* b2);
	static bool CheckToCollisionSphere2Sphere(SphereCollider* s1, SphereCollider* s2);

protected:
	ColliderType _colliderType;
	bool _showDedug = true;

public:
	unordered_set<Collider*> _collisionMap;

	uint32 _flag = 0;
};

