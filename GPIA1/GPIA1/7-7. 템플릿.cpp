#include <iostream>
using namespace std;

template<typename T = int, int SIZE = 100>
class RandomBox
{
public:
	T GetRandomData()
	{
		int index = rand() % SIZE;
		return data[index];
	}

public:
	T data[SIZE];
};

template<>
class RandomBox<int>
{
public:
	int GetRandomData()
	{
		int index = rand() % 100;
		return data[index];
	}

public:
	int data[100];
};

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<>
void Print(int a)
{
	cout << "int" << endl;
}

int main(void)
{
	RandomBox<int, 100> rb1;
	RandomBox<float, 200> rb2;
	RandomBox<> rb3;
}