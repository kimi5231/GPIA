#include <iostream>
using namespace std;

class Marine
{
public:
	// Ư�� ���� ��ü�� ����
	void TakeDamage(int damage)
	{
		hp -= damage;
	}

	// Ư�� ���� ��ü�� ����
	static void SetAttack(int value)
	{
		attack = value;
	}
public:
	// Ư�� ���� ��ü�� ����
	int hp = 40;

	// Ư�� ���� ��ü�� ����
	static int attack;
};

int Marine::attack = 6;

class Player
{
public:
	Player()
	{
		id = s_idGenerator++;
	}
public:
	int id;
	static int s_idGenerator;
};

int Player::s_idGenerator = 1;

class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}
public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }
private:
	int _userCount = 0;
};

#define GET_MANAGER (UserManager::GetInstance())

int main()
{
	Marine::SetAttack(10);

	GET_MANAGER->AddUser();
	//UserManager::GetInstance()->AddUser();

	cout << UserManager::GetInstance()->GetUserCount() << endl;
}