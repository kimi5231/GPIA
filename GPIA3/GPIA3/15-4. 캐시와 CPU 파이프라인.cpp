#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

//int buffer[10000][10000];

int x = 0;
int y = 0;
int r1 = 0;
int r2 = 0;

// 휘발성 있는 변수.
// 최적화 금지.
volatile bool ready = false;

//void Thread_1()
//{
//	while (ready == false){}
//
//	// 독립적인 코드이기 때문에 순서가 바뀔 수 있다.
//	y = 1; // Store y
//	r1 = x; // Load x
//}
//
//void Thread_2()
//{
//	while (ready == false){}
//
//	x = 1; // Store y
//	r2 = y; // Load x
//}

void Thread_1()
{
	while (ready == false) {}

	cout << "Yeah!!!" << endl;
}

int main()
{
	{
		//::memset(buffer, 0, sizeof(buffer));

		//// cash hit
		//{
		//	auto start = ::GetTickCount64();

		//	__int64 sum = 0;

		//	for (int i = 0; i < 10000; ++i)
		//	{
		//		for (int j = 0; j < 10000; ++j)
		//			sum += buffer[i][j];
		//	}

		//	auto end = ::GetTickCount64();

		//	cout << "Elapsed Tick " << (end - start) << endl;
		//}

		//{
		//	auto start = ::GetTickCount64();

		//	__int64 sum = 0;

		//	for (int i = 0; i < 10000; ++i)
		//	{
		//		for (int j = 0; j < 10000; ++j)
		//			sum += buffer[j][i];
		//	}

		//	auto end = ::GetTickCount64();

		//	cout << "Elapsed Tick " << (end - start) << endl;
		//}
	}

	{
		/*int count = 0;

		while (true)
		{
			ready = false;
			count++;

			x = y = r1 = r2 = 0;

			thread t1(Thread_1);
			thread t2(Thread_2);

			ready = true;

			t1.join();
			t2.join();

			if (r1 == 0 && r2 == 0)
				break;
		}

		cout << count << endl;*/
	}

	{
		thread t1(Thread_1);

		// 1초 대기.
		this_thread::sleep_for(1s);

		ready = true;

		t1.join();
	}
}