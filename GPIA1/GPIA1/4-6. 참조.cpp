#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 1) 값(복사) 전달 방식
void PrintByCopy(StatInfo player)
{
	cout << "-----------------" << endl;
	cout << "HP: " << player.hp << endl;
	cout << "ATT: " << player.attack << endl;
	cout << "DEF: " << player.defence << endl;
	cout << "-----------------" << endl;
}

// 2) 주소 전달 방식
void PrintByPointer(StatInfo* player)
{
	cout << "-----------------" << endl;
	cout << "HP: " << player->hp << endl;
	cout << "ATT: " << player->attack << endl;
	cout << "DEF: " << player->defence << endl;
	cout << "-----------------" << endl;
}

// 3) 참조 전달 방식
void PrintByRef(const StatInfo& player)
{
	cout << "-----------------" << endl;
	cout << "HP: " << player.hp << endl;
	cout << "ATT: " << player.attack << endl;
	cout << "DEF: " << player.defence << endl;
	cout << "-----------------" << endl;
}

int main()
{
	StatInfo player = { 100, 10, 1 };

	PrintByCopy(player);

	// 1) 원본을 건드리고 싶을 때 (원격)
	// 2) 복사 비용X
	PrintByPointer(&player);

	PrintByRef(player);
}