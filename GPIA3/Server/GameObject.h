#pragma once
class GameObject : public enable_shared_from_this<GameObject>
{
public:
	GameObject();
	virtual ~GameObject();

	// Object 积己 窃荐
	static PlayerRef CreatePlayer();
	static MonsterRef CreateMonster();

public:
	Protocol::ObjectInfo info;
	GameRoomRef room;

private:
	// ID 积己扁
	static atomic<uint64> s_idGenerator;
};