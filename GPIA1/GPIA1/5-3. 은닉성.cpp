#include <iostream>
using namespace std;

// OOP 3�� ���
// - ��Ӽ� << inher itance
// - ���м� << data hiding (ĸ��ȭ encapsulation)
// - ������

// ���� ������

class Car
{
public:
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }
	void TurnKey()
	{
		PutFuellnEngine();
	}
protected:
	void Disassemble() { }
	void PutFuellnEngine() { }
	void ConnectCircuit() { }
public:
	int a;
};

class SuperCar : private Car
{
public:
	void Test()
	{
		MoveHandle();
		Disassemble();
	}
};

class UltraSuperCar : public SuperCar
{
public:
	void Test()
	{
		//MoveHandle();
	}
};

class Knight
{
public:
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
		{

		}
	}

	int GetHp()
	{
		return _hp;
	}
public:
	int _hp = 100;
};

int main()
{
	Knight k1;
	k1.SetHp(100);
}