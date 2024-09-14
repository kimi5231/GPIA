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

// �� ������� ����
#define DEF_SCISSORS 0

int main()
{
	// �����
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			cout << "*";
		cout << endl;
	}
	cout << endl;

	// ������
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
			cout << i << "x" << j << " = " << i*j << endl;
		cout << endl;
	}
	cout << endl;

	// ������ ����
	int round = 1;
	int hp = 100;	// ����HP
	int damage = 25;	// �÷��̾� ������

	while (true)
	{
		// ���� ����
		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "Round: " << round << " ���� ü��: " << hp << endl;

		if (hp == 0)
		{
			cout << "���� óġ!" << endl;
			break;
		}
		
		if (round == 5)
		{
			cout << "���� ���� ����" << endl;
			break;
		}

		round++;
	}
	cout << endl;
	
	// ����-����-��
	srand(time(0));

	while (true)
	{
		cout << "����(0) ����(1) ��(2)�� ����ּ���!" << endl;
		cout << ">> ";

		// �����
		int value;
		cin >> value;

		// ��ǻ��
		int computerValue = rand() % 3;

		if (value == GBB_SCISSORS)
		{
			switch (computerValue)
			{
			case GBB_SCISSORS:
				cout << "����(player) vs ����(computer) : �����ϴ�!" << endl;
				break;
			case GBB_ROCK:
				cout << "����(player) vs ����(computer) : �����ϴ�!" << endl;
				break;
			case GBB_PAPER:
				cout << "����(player) vs ��(computer) : �̰���ϴ�!" << endl;
				break;
			}
		}
		else if (value == GBB_ROCK)
		{
			switch (computerValue)
			{
			case GBB_SCISSORS:
				cout << "����(player) vs ����(computer) : �̰���ϴ�!" << endl;
				break;
			case GBB_ROCK:
				cout << "����(player) vs ����(computer) : �����ϴ�!" << endl;
				break;
			case GBB_PAPER:
				cout << "����(player) vs ��(computer) : �����ϴ�!" << endl;
				break;
			}
		}
		else if (value == GBB_PAPER)
		{
			switch (computerValue)
			{
			case GBB_SCISSORS:
				cout << "��(player) vs ����(computer) : �����ϴ�!" << endl;
				break;
			case GBB_ROCK:
				cout << "��(player) vs ����(computer) : �̰���ϴ�!" << endl;
				break;
			case GBB_PAPER:
				cout << "��(player) vs ��(computer) : �����ϴ�!" << endl;
				break;
			}
		}
	}
}