#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #9]
// 궁수가 죽으면 펫도 같이 죽는 사양이 추가되었습니다.
// 그런데 왜 프로그램도 같이 죽는걸까요?
// 이유를 찾아서 고쳐주세요!

// [Solution]
// Archer가 죽을 때 펫의 메모리를 해제하고
// 후에 Archer 메모리를 해제할 때 펫의 메모리 해제를 또 함.
// _pet != nullptr이라는 조건이 걸려있긴 하지만
// 메모리를 해제한다고 _pet이 nullptr이 되는 것은 아니기 때문에
// 최종적으로 펫의 메모리 해제를 두 번 하게 되어 크래시 발생.
// 따라서, Archer가 죽어 펫의 메모리를 해제할 때,
// 메모리 해제 후 _pet을 nullptr로 만들어
// 후에 메모리를 두 번 해제하지 않도록 하여 문제 해결.

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Archer* archer = new Archer(new Pet());
	archer->_hp = 100;
	archer->_maxHp = 100;
	archer->_attack = 20;

	Knight* knight = new Knight();	
	knight->_hp = 150;
	knight->_maxHp = 150;
	knight->_attack = 100;
	
	int damage = knight->GetAttackDamage();
	archer->AddHp(-damage);

	delete archer;
	delete knight;
}
