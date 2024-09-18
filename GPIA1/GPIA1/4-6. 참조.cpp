#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 1) ��(����) ���� ���
void PrintByCopy(StatInfo player)
{
	cout << "-----------------" << endl;
	cout << "HP: " << player.hp << endl;
	cout << "ATT: " << player.attack << endl;
	cout << "DEF: " << player.defence << endl;
	cout << "-----------------" << endl;
}

// 2) �ּ� ���� ���
void PrintByPointer(StatInfo* player)
{
	cout << "-----------------" << endl;
	cout << "HP: " << player->hp << endl;
	cout << "ATT: " << player->attack << endl;
	cout << "DEF: " << player->defence << endl;
	cout << "-----------------" << endl;
}

// 3) ���� ���� ���
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

	// 1) ������ �ǵ帮�� ���� �� (����)
	// 2) ���� ���X
	PrintByPointer(&player);

	PrintByRef(player);
}