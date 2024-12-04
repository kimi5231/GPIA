#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> sum = 0;

void Add()
{
	for (int i = 0; i < 100; ++i)
	{
		sum++;
		// 세 단계 실행
		// int eax = sum;
		// eax = eax + 1;
		// sum = eax;
	}
}

void Sub()
{
	for (int i = 0; i < 100; ++i)
	{
		sum--;
		// int eax = sum;
		// eax = eax - 1;
		// sum = eax;
	}
}

void Test()
{
	for (int i = 0; i < 10000; ++i)
	{
		// p는 Stack 영역에 있어 문제X.
		int* p = new int();

		*p = 100;

		delete p;
	}
}

int main()
{
	// int temp = sum;
	int temp = sum.load();
	
	// sum = 10;
	sum.store(10);

	// 이전의 값 얻어오기.
	int tmp = sum.exchange(10);
	int prev = sum.fetch_add(10);

	thread t1(Add);
	thread t2(Sub);
	
	t1.join();
	t2.join();

	cout << sum << endl;
}