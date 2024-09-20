#include <iostream>
using namespace std;

// OOP 3대 요소
// - 상속성 << inher itance
// - 은닉성 << data hiding (캡슐화 encapsulation)
// - 다형성

// 접근 지정자

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