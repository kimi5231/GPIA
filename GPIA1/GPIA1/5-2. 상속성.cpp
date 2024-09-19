#include <iostream>
using namespace std;

// OOP 3대 요소
// - 상속성 << inher itance
// - 은닉성
// - 다형성

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// -- Arrow, Fireball
// - Env

// Is-A vs Has-A
class Player
{
public:
	void Move() { }
	void Attack() { }
	void Die() { }

public:
	int _type;
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{
public:

public:
	int _stamina;
};

class Archer : public Player
{
public:

public:
	int _arrowCount;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

void Fight(Player* p1, Player* p2)
{

}

int main()
{
	Knight k1;
	
	Mage m1;

	Fight(&k1, &m1);
}