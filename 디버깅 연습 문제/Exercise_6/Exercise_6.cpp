#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #6]
// 반격 시스템이 도입되어,
// 기사는 자신을 공격한 대상을 똑같이 공격합니다.
// 기사 2을 생성해서 위 사양을 테스트하는데...
// 바로 크래시가 나고 있습니다.
// 또 뭐가 문제인지 원인을 찾아주세요!

// [Solution]
// 데미지를 받을 때 바로 반격을 하기 때문에
// 서로 끝없이 반격을 해 스택 메모리가 고갈되어 크래시 발생.
// 반격하기 전에 스스로의 체력을 확인하여
// 살아있을 때만 반격하도록 해 해결.

int main()
{
	Knight* k1 = new Knight();
	k1->_hp = 100;
	k1->_maxHp = 100;
	k1->_attack = 100;

	Knight* k2 = new Knight();
	k2->_hp = 100;
	k2->_maxHp = 100;
	k2->_attack = 100;

	k1->OnDamaged(k2);

	delete k1;
	delete k2;
}
