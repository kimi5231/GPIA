#pragma once

enum class SceneType
{
	None,
	DevScene,
	GameScene,
	EditScene,
};

enum LAYER_TYPE
{
	LAYER_BACKGROUND,
	LAYER_OBJECT,
	LAYER_UI,

	LAYER_MAXCOUNT,
};

enum class ColliderType : uint8
{
	Box,
	Sphere,
};

enum COLLISION_LAYER_TYPE
{
	CLT_OBJECT,
	CLT_GROUND,
	CLT_WALL,
};