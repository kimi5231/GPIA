#include <iostream>
using namespace std;

void AddHp(int* hp, int value)
{
	*hp += value;
}

int main()
{
	int hp = 100;

	// [타입]* [이름];
	// * = vhdlsxj
	// 주소값을 담는 바구니
	// 주소값을 타고 가면 -> 무엇이 있느냐?
	int* ptr = &hp;
	int** pptr = &ptr;

	AddHp(&hp, 10);
	
	cout << hp << endl;
	cout << *ptr << endl;
	cout << **pptr << endl;
}