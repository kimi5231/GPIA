#include <iostream>
using namespace std;

class Player
{
public:
	Player() { cout << "Player()" << endl; }
	virtual ~Player() { cout << "Player()" << endl; }
};

class Pet
{

};

class Archer : public Player
{
public:
	Archer()
	{
		_pet = new Pet();
		cout << "Archer()" << endl;
	}

	virtual ~Archer()
	{
		delete _pet;
		cout << "~Archer()" << endl;
	}

private:
	Pet* _pet;
};

int main()
{
	Player* player = new Archer();
	delete player;
}