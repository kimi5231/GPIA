#include <iostream>
using namespace std;

int a;
int b;

bool result;

bool isRich;
bool isTall;

int main()
{
	a = 10;
	b = 20;

	// ������
	result = (a == b);
	cout << result << endl;

	// �ٸ���
	result = (a != b);
	cout << result << endl;
	
	// <
	// <=
	// >
	// >=

	isRich = true;
	isTall = false;

	// ! not
	// && and
	result = isRich && isTall;
	// || or
	result = isRich || isTall;
}