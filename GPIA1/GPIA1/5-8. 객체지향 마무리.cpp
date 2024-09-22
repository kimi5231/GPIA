#include <iostream>
using namespace std;

class Object
{
	void Move() {}
};

class IFly
{
	virtual void Fly() = 0;
	virtual void Land() = 0;
};

class Player : public Object, public IFly
{
public:
	Player() {}
	~Player() {}

	virtual void Fly() override {}
	virtual void Land() override {}

	virtual void Shout() {}
public:
	int hp = 10;
};

void AddObject(Player* player)
{
	player->Shout();
}

void FlyTest(IFly* fly)
{

}

int main()
{
	Player p;
	FlyTest(&p);
}