#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include "windows.h"

using namespace std;

mutex m;
queue<int> q;
HANDLE hEvent;

// 유저레벨 오브젝트
condition_variable cv;

void Producer()
{
	while (true)
	{
		unique_lock<mutex> lock(m);

		q.push(100);
		//::SetEvent(hEvent);
		// 하나만 깨우기.
		cv.notify_one();

		this_thread::sleep_for(100ms);
	}
}

void Consumer()
{
	while (true)
	{
		//::WaitForSingleObject(hEvent, INFINITE);
		//::ResetEvent(hEvent);

		unique_lock<mutex> lock(m);

		cv.wait(lock, []() {return q.empty() == false;});
		// 1) Lock을 잡으려고 시도 (이미 잡혔으면 skip)
		// 2) 조건 확인
		// - 만족O => 바로 빠져 나와서 이어서 코드 진행
		// - 만족X => Lock을 풀어주고 대기 상태로 전환

		//if (q.empty() == false)
		{
			int data = q.front();
			q.pop();
			cout << data << endl;
		}
	}
}

int main()
{
	// 커널 오브젝트
	// - Usage Count
	// - Signal (파란불) / Non-Signal (빨간불)

	hEvent = ::CreateEvent(NULL/*보안속성*/, FALSE/*bManualReset*/, FALSE/*초기상태*/, NULL);

	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	::CloseHandle(hEvent);
}