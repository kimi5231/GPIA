#pragma once
class GameObject : public enable_shared_from_this<GameObject>
{
public:
	GameObject();
	virtual ~GameObject();

	// Object 생성 함수
	static PlayerRef CreatePlayer();
	static MonsterRef CreateMonster();

public:
	Protocol::ObjectInfo info;
	GameRoomRef room;

private:
	// ID 생성기
	static atomic<uint64> s_idGenerator;
};