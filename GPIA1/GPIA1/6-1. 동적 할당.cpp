#include <iostream>
using namespace std;

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }
	~Monster() { cout << "~Monster()" << endl; }
public:
	int _hp = 0;
};

int main()
{
	// malloc + free
	void* ptr = malloc(4);
	Monster* m1 = (Monster*)ptr;
	m1->_hp = 100;
	free(ptr);

	// new + delete
	Monster* m2 = new Monster[5]();
	m2[1]._hp = 100;
	delete[] m2;

	m2 = nullptr;
}