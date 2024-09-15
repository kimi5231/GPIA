#include <iostream>
using namespace std;

int AddHp(int hp, int value)
{
	hp += value;
	return hp;
}

int main()
{
	int hp = 100;

	hp = AddHp(hp, 20);

	cout << hp << endl;
}