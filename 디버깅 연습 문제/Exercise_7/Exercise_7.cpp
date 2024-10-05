﻿#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"

// [Bug Report #7]
// 게임이 완전 흥행해서
// 기사 말고도 궁수, 법사 등이 추가되었습니다.
// 이를 위해 기사/궁수/법사가 공통으로 사용할
// Player 부모 클래스를 만들었습니다.

// 아울러 궁수가 펫이 없는게 말이 되냐?? 는 사장님의 지적에 따라
// 궁수 클래스에 한정해서 [펫]의 개념이 들어갑니다.
// [펫은 ]사냥을 도와주고 버프를 주는 기능을 할 예정입니다.
// 펫은 임시로 Archer 생성자에서 만들어주고 있습니다.
// (좋은 설계는 아니지만, 딱히 문제가 되지 않는 것을 시니어 프로그래머에게 컨펌 받았습니다)

// 우리 MMO에선 한달동안 서버 점검 없이 실행되길 원합니다.
// 플레이어를 생성하고 삭제하는 테스트를 해보고 있는데...
// 얼마 지나지 않아 프로그램이 먹통이 됩니다!
// 프로그램이 크래시 나는 이유가 도대체 뭘까요?

// 주의) 
// x64에서는 1분 정도 기다려야 크래시가 나기 때문에,
// x86으로 바꿔서 실행하시길 추천 드립니다!
// 위쪽에서 [Debug][x86] 설정

// [Solution]
// Player와 Archer의 소멸자를 가상 함수로 만들지 않아
// Player를 생성하고 메모리를 해제할 때,
// Archer의 소멸자가 제대로 호출되지 않아
// 펫의 메모리 해제가 이루어지지 않음.
// 따라서, 메모리가 부족해져 크래시 발생.
// Player와 Archer의 소멸자를 가상함수로 만들어 해결.
// + Player 소멸자에만 virtual을 붙여도 되지만,
// 명확함을 위해 Archer 소멸자에도 붙임.

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		// 나중엔 궁수, 법사 등 추가 예정
		Player* p = nullptr;

		switch (rand() % 3)
		{
		case 0:
			p = new Knight();
			p->_hp = 100;
			p->_attack = 100;
			break;
		case 1:
			p = new Archer();
			p->_hp = 100;
			p->_attack = 100;
			break;
		case 2:
			p = new Mage();
			p->_hp = 100;
			p->_attack = 100;
			break;
		}		

		delete p;
	}
	
}
