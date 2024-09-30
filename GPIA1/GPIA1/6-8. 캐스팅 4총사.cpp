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
	// static_cast: 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용
	// 1) int <-> float
	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	// 2) Player -> Knight*
	Knight* k = new Knight();
	Player* p = k;
	Knight* k2 = static_cast<Knight*>(p);

	// dynamic_cast: 상속 관계에서의 안전 변환
	// 다형성을 활용하는 방식
	// RTTI (Run Time Type Information)
	Knight* k3 = dynamic_cast<Knight*>(p);
	if (k3 != nullptr)
	{

	}

	// const_cast
	const char* name = "Name";
	char* name2 = const_cast<char*>(name);

	// reinterpret_cast
	// 위험하고 강력한 형태
	// 포인터 -> 전혀 관계없는 다른 포인터로 변환
	Dog* dog = reinterpret_cast<Dog*>(p);
}