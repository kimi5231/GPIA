#include <iostream>
using namespace std;

const int SCISSORS = 0;
const int ROCK = 1;
const int PAPER = 2;

enum ENUM_GBB
{
	GBB_SCISSORS = 0,
	GBB_ROCK = 1,
	GBB_PAPER = 2
};

// 잘 사용하지 않음
#define DEF_SCISSORS 0

int main()
{
	// 별찍기
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			cout << "*";
		cout << endl;
	}
	cout << endl;

	// 구구단
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
			cout << i << "x" << j << " = " << i*j << endl;
		cout << endl;
	}
	cout << endl;

	// 간단한 전투
	int round = 1;
	int hp = 100;	// 몬스터HP
	int damage = 25;	// 플레이어 데미지

	while (true)
	{
		// 전투 진행
		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "Round: " << round << " 몬스터 체력: " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}
		
		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}
	cout << endl;
	
	// 가위-바위-보
	srand(time(0));

	while (true)
	{
		cout << "가위(0) 바위(1) 보(2)를 골라주세요!" << endl;
		cout << ">> ";

		// 사용자
		int value;
		cin >> value;

		// 컴퓨터
		int computerValue = rand() % 3;

		if (value == GBB_SCISSORS)
		{
			switch (computerValue)
			{
			case GBB_SCISSORS:
				cout << "가위(player) vs 가위(computer) : 비겼습니다!" << endl;
				break;
			case GBB_ROCK:
				cout << "가위(player) vs 바위(computer) : 졌습니다!" << endl;
				break;
			case GBB_PAPER:
				cout << "가위(player) vs 보(computer) : 이겼습니다!" << endl;
				break;
			}
		}
		else if (value == GBB_ROCK)
		{
			switch (computerValue)
			{
			case GBB_SCISSORS:
				cout << "바위(player) vs 가위(computer) : 이겼습니다!" << endl;
				break;
			case GBB_ROCK:
				cout << "바위(player) vs 바위(computer) : 비겼습니다!" << endl;
				break;
			case GBB_PAPER:
				cout << "바위(player) vs 보(computer) : 졌습니다!" << endl;
				break;
			}
		}
		else if (value == GBB_PAPER)
		{
			switch (computerValue)
			{
			case GBB_SCISSORS:
				cout << "보(player) vs 가위(computer) : 졌습니다!" << endl;
				break;
			case GBB_ROCK:
				cout << "보(player) vs 바위(computer) : 이겼습니다!" << endl;
				break;
			case GBB_PAPER:
				cout << "보(player) vs 보(computer) : 비겼습니다!" << endl;
				break;
			}
		}
	}
}