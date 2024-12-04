#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <windows.h>

using namespace std;

class Lock
{
public:
	void lock()
	{
		// CAS (Compare-And-Swap)
		bool expected = false;
		bool desired = true;

		// SpinLock
		while (_flag.compare_exchange_strong(OUT expected, desired) == false)
		{
			expected = false;
		}

		/*if (_flag == expected)
		{
			_flag = desired;
			return true;
		}
		else
		{
			expected = _flag;
			return false;
		}*/
	}

	void unlock()
	{
		_flag = false;
	}

private:
	atomic<bool> _flag = false;
};

Lock m;
vector<int> v;

void Push()
{
	for (int i = 0; i < 10000; ++i)
	{
	
		std::lock_guard<Lock> lockGuard(m);

	
		v.push_back(i);
	}
}

int main()
{
	thread t1(Push);
	thread t2(Push);

	t1.join();
	t2.join();

	cout << v.size() << endl;
}