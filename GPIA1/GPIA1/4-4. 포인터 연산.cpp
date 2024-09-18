#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print(int* ptr, int count)
{
	for (int i = 0; i < count; ++i)
		cout << ptr[i] << endl;
}

int main()
{
	// ������ ����
	// - �ּ� ������ (&)
	// - ��� ������ (+-)
	// - ���� ������ (*)
	// - ���� ��� ������ (->)
		
	int a = 10;
	int b = 20;

	Swap(&a, &b);

	cout << a << endl;
	cout << b << endl;
	cout << endl;

	int numbers[100] = { 1,2,3,4,5,6 };

	int* ptr = numbers;
	*(ptr + 3) = 400;

	ptr[0] = 100;

	ptr += 1;
	*ptr = 200;

	Print(numbers, 6);
	cout << endl;

	StatInfo monster;
	monster.hp = 100;
	monster.attack = 10;
	monster.defence = 1;

	StatInfo* ptr2 = &monster;

	cout << (*ptr2).hp << endl;
	cout << ptr2->attack << endl;
}