#include <iostream>
using namespace std;

class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	Pet(const Pet& pet) { cout << "Pet(const Pet&)" << endl; }
	~Pet() { cout << "~Pet()" << endl; }
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}

	Knight(const Knight& k)
	{
		_hp = k._hp;
		_pet = new Pet(*k._pet);
	}

public:
	int _hp = 10;;
	Pet* _pet;
};

int main()
{
	Knight k1;
	k1._hp = 200;

	Knight k2 = k1;
}