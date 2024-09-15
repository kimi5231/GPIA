#include <iostream>
using namespace std;

int Add(int a, int b);
void Test1();
void Test2();
void Test3();

int hp;

void Test(int a)
{
	hp = 100;
}

void Test(float a)
{
	cout << hp << endl;
}

void Test1()
{
	Test2();
}

void Test2()
{
	Test3();
}

void Test3()
{

}

int main()
{
	Add(10, 20);
	Test(10);
	Test(3.14f);
}

int Add(int a, int b)
{
	cout << a + b << endl;
	return a + b;
}