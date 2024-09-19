#include <iostream>
#include "5-1. Player.h"
using namespace std;

// 객체지향 (Objext Oriendted Programming)
// 데이터 + 로직

class Knight
{
public:
	// 기본 생성자(constructor)
	Knight()
	{
		hp = 0;
		attack = 0;
		defence = 0;
		cout << "Knight()" << endl;
	}

	// 기타 생성자
	Knight(int hp, int attack, int defence)
	{
		this->hp = hp;
		this->attack = attack;
		this->defence = defence;
		cout << "Knight()" << endl;
	}

	// 복사 생성자
	Knight(const Knight& other)
	{
		this->hp = other.hp;
		this->attack = other.attack;
		this->defence = other.defence;
		cout << "Knight(const Knight&)" << endl;
	}

	// 소멸자(destructor)
	~Knight()
	{
		cout << "~Knight()" << endl;
	}

	// 멤버 함수
	void Attack() { cout << "Attack" << endl; }
	void Die() { cout << "Die" << endl; }
	void HealMe(int value)
	{ 
		hp += value;
	}
public:
	// 멤버 변수
	int hp;
	int attack;
	int defence;
};

int main()
{
	// 객체 (instance)
	Player p1;

	Knight k1(100, 10, 1);
	Knight k2(k1);
	
	cout << k1.hp << endl;
}