#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include "windows.h"

using namespace std;

mutex m;
queue<int> q;
HANDLE hEvent;

// �������� ������Ʈ
condition_variable cv;

void Producer()
{
	while (true)
	{
		unique_lock<mutex> lock(m);

		q.push(100);
		//::SetEvent(hEvent);
		// �ϳ��� �����.
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
		// 1) Lock�� �������� �õ� (�̹� �������� skip)
		// 2) ���� Ȯ��
		// - ����O => �ٷ� ���� ���ͼ� �̾ �ڵ� ����
		// - ����X => Lock�� Ǯ���ְ� ��� ���·� ��ȯ

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
	// Ŀ�� ������Ʈ
	// - Usage Count
	// - Signal (�Ķ���) / Non-Signal (������)

	hEvent = ::CreateEvent(NULL/*���ȼӼ�*/, FALSE/*bManualReset*/, FALSE/*�ʱ����*/, NULL);

	thread t1(Producer);
	thread t2(Consumer);

	t1.join();
	t2.join();

	::CloseHandle(hEvent);
}