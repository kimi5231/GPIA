#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

// Mutual Exclusive (��ȣ��Ÿ��): �� ���� �ϳ��� �̿��� �� �ִ�.
mutex m;
vector<int> v;

// RAII (Resource Acquisition Is Initialization)

template<typename T>
class LockGuard
{
public:
	LockGuard(T& m) : _mutex(m)
	{
		_mutex.lock();
	}

	~LockGuard()
	{
		_mutex.unlock();
	}

private:
	T& _mutex;
};

void Push()
{
	for (int i = 0; i < 10000; ++i)
	{
		// lock ����, ���� �ڵ�ȭ.
		//LockGuard<mutex> lockGuard(m);
		//std::lock_guard<mutex> lockGuard(m);
		
		// lock ���� �̷�� ����
		std::unique_lock<mutex> uniqueLock(m, std::defer_lock);

		uniqueLock.lock();

		//m.lock();
		v.push_back(i);
		//m.unlock();
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