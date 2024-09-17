#include <iostream>
using namespace std;

int main()
{
	int arr[5];

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10;

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << endl;

	int arr2[] = { 1, 2, 3, 4, 5 };
	int arr3[10] = { 1, 2, 3, 4, 5 };
}