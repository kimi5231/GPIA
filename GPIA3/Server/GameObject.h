#pragma once
class GameObject : public enable_shared_from_this<GameObject>
{
public:
	GameObject();
	virtual ~GameObject();

	// Object ���� �Լ�
	static PlayerRef CreatePlayer();
	static MonsterRef CreateMonster();

public:
	Protocol::ObjectInfo info;
	GameRoomRef room;

private:
	// ID ������
	static atomic<uint64> s_idGenerator;
};