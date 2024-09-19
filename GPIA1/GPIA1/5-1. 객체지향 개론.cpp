#include <iostream>
#include "5-1. Player.h"
using namespace std;

// ��ü���� (Objext Oriendted Programming)
// ������ + ����

class Knight
{
public:
	// �⺻ ������(constructor)
	Knight()
	{
		hp = 0;
		attack = 0;
		defence = 0;
		cout << "Knight()" << endl;
	}

	// ��Ÿ ������
	Knight(int hp, int attack, int defence)
	{
		this->hp = hp;
		this->attack = attack;
		this->defence = defence;
		cout << "Knight()" << endl;
	}

	// ���� ������
	Knight(const Knight& other)
	{
		this->hp = other.hp;
		this->attack = other.attack;
		this->defence = other.defence;
		cout << "Knight(const Knight&)" << endl;
	}

	// �Ҹ���(destructor)
	~Knight()
	{
		cout << "~Knight()" << endl;
	}

	// ��� �Լ�
	void Attack() { cout << "Attack" << endl; }
	void Die() { cout << "Die" << endl; }
	void HealMe(int value)
	{ 
		hp += value;
	}
public:
	// ��� ����
	int hp;
	int attack;
	int defence;
};

int main()
{
	// ��ü (instance)
	Player p1;

	Knight k1(100, 10, 1);
	Knight k2(k1);
	
	cout << k1.hp << endl;
}