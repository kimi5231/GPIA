#include <iostream>
using namespace std;

// static_cast
// dynamic_cast
// const_cast
// reinterpret_cast

class Player
{
public:
	Player() {}
	virtual ~Player() {}
};

class Knight : public Player
{
public:
	Knight() {}
	virtual ~Knight() {}
};

class Dog
{

};

int main()
{
	// static_cast: Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ���
	// 1) int <-> float
	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	// 2) Player -> Knight*
	Knight* k = new Knight();
	Player* p = k;
	Knight* k2 = static_cast<Knight*>(p);

	// dynamic_cast: ��� ���迡���� ���� ��ȯ
	// �������� Ȱ���ϴ� ���
	// RTTI (Run Time Type Information)
	Knight* k3 = dynamic_cast<Knight*>(p);
	if (k3 != nullptr)
	{

	}

	// const_cast
	const char* name = "Name";
	char* name2 = const_cast<char*>(name);

	// reinterpret_cast
	// �����ϰ� ������ ����
	// ������ -> ���� ������� �ٸ� �����ͷ� ��ȯ
	Dog* dog = reinterpret_cast<Dog*>(p);
}