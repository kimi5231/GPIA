#include <iostream>
using namespace std;

void AddHp(int* hp, int value)
{
	*hp += value;
}

int main()
{
	int hp = 100;

	// [Ÿ��]* [�̸�];
	// * = vhdlsxj
	// �ּҰ��� ��� �ٱ���
	// �ּҰ��� Ÿ�� ���� -> ������ �ִ���?
	int* ptr = &hp;
	int** pptr = &ptr;

	AddHp(&hp, 10);
	
	cout << hp << endl;
	cout << *ptr << endl;
	cout << **pptr << endl;
}