#include <iostream>
using namespace std;

int a;
int b;

int hp;

int main()
{
	// + - * / %
	a = 10;
	b = 3;

	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << (a * b) << endl;
	cout << (a / b) << endl;
	cout << (a % b) << endl;

	hp = 100;

	hp = hp + 5;
	hp += 5;

	hp = hp - 5;
	hp += 5;

	hp = hp * 5;
	hp += 5;

	hp = hp / 5;

	hp = hp % 5;
}