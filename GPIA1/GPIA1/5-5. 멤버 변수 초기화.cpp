#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	~Player()
	{
		cout << "~Player()" << endl;
	}
public:
	
};

class Inventory
{
public:
	Inventory()
	{
		cout << "Inventory()" << endl;
	}

	Inventory(int a)
	{
		_a = a;
		cout << "Inventory(int a)" << endl;
	}

	~Inventory()
	{
		cout << "~Inventory()" << endl;
	}
public:
	int _a = 0;
};

class Knight : public Player
{
public:
	Knight() : _hp(0), _inventory(100), _hpRef(_hp), _hpConst(_hp)
	/*
		선처리 영역
		Player()
		_inventory = Inventory()
	*/
	{
		cout << "Knight()" << endl;
	}

	~Knight()
	{
		cout << "~Knight()" << endl;
	}
public:
	int _hp = 0;
	int _defence = 20;
	int& _hpRef;
	const int _hpConst;
	Inventory _inventory;
};

int main()
{
	Knight k1;
}