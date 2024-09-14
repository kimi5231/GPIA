#include <iostream>
using namespace std;

// 0 가위 1 바위 2 보
int choice;

int main()
{
	// if () {}
	// if-else
	// if-else if-else

	choice = 3;

	if (choice == 0)
		cout << "가위를 냈습니다." << endl;
	else if (choice == 1)
		cout << "바위를 냈습니다." << endl;
	else if (choice == 2)
		cout << "보를 냈습니다." << endl;
	else
		cout << "무엇을 낸 것인가요?" << endl;

	// swich-case break
	switch (choice)
	{
	case 0:
		cout << "가위를 냈습니다." << endl;
		break;
	case 1:
		cout << "바위를 냈습니다." << endl;
		break;
	case 2:
		cout << "보를 냈습니다." << endl;
		break;
	default:
		cout << "무엇을 낸 것인가요?" << endl;
		break;
	}
}