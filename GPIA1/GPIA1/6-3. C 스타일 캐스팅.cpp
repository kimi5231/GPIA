#include <iostream>
using namespace std;

class Player
{
public:
	virtual ~Player() {}
};

class Knight : public Player
{
public:
	Player* target;
};

class Dog
{
public:
	int age;
	int size;
};

int main()
{
	// C 스타일 캐스팅

	// 값 타입 변환
	// 특징) 의미를 유지하기 위해서 원본 객체와 다른 비트열 재구성
	{
		int a = 123456789;
		float b = (float)a;
		int c = 0;
	}

	// 참조 타입 변환
	{
		int a = 123456789;
		float b = (float&)a;
		int c = 0;
	}

	// 안전한 변환 (의미가 100% 일치)
	{
		int a = 123456789;
		__int64 b = (__int64)a;
		int c = 0;
	}

	// 불안전한 변환
	{
		int a = 123456789;
		short b = (short)a;
		int c = 0;
	}

	// 암시적 변환
	{
		int a = 123456789;
		float b = a;
	}

	Knight* k = new Knight();

	Dog* dog = (Dog*)k;
	dog->age = 10;
}