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

	void SetCollisionLayerType(COLLISION_LAYER_TYPE layer) { _collisionLayer = layer; }
	COLLISION_LAYER_TYPE GetCollisionLayerType() { return _collisionLayer; }

	void SetCollisionFlag(uint32 flag) { _collisionFlag = flag; }
	uint32 GetCollisionFlag() { return _collisionFlag; }

	void ResetCollisionFlag() { _collisionFlag = 0; }
	void AddCollisionFlagLayer(COLLISION_LAYER_TYPE layer);
	void RemoveCollisionFlagLayer(COLLISION_LAYER_TYPE layer);

protected:
	ColliderType _colliderType;
	bool _showDedug = true;

public:
	unordered_set<Collider*> _collisionMap;

	COLLISION_LAYER_TYPE _collisionLayer = CLT_OBJECT;
	uint32 _collisionFlag = ~0;
};

