#include <iostream>
using namespace std;

// 0 ���� 1 ���� 2 ��
int choice;

int main()
{
	// if () {}
	// if-else
	// if-else if-else

	choice = 3;

	if (choice == 0)
		cout << "������ �½��ϴ�." << endl;
	else if (choice == 1)
		cout << "������ �½��ϴ�." << endl;
	else if (choice == 2)
		cout << "���� �½��ϴ�." << endl;
	else
		cout << "������ �� ���ΰ���?" << endl;

	// swich-case break
	switch (choice)
	{
	case 0:
		cout << "������ �½��ϴ�." << endl;
		break;
	case 1:
		cout << "������ �½��ϴ�." << endl;
		break;
	case 2:
		cout << "���� �½��ϴ�." << endl;
		break;
	default:
		cout << "������ �� ���ΰ���?" << endl;
		break;
	}
}