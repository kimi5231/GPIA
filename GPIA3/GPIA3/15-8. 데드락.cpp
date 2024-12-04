#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <windows.h>
#include <map>

using namespace std;

mutex m1;
mutex m2;

class User
{

};

class UserManager
{
public:
	User* GetUser(int id)
	{
		unique_lock<mutex> guard(_lock);

		if (_users.find(id) == _users.end())
			return nullptr;

		return _users[id];
	}

private:
	map<int, User*> _users;
	mutex _lock;
};

void Thread_1()
{
	for (int i = 0; i < 10000; ++i)
	{
		lock_guard<mutex> lockGuard1(m1);
		lock_guard<mutex> lockGuard2(m2);
	}
}

void Thread_2()
{
	for (int i = 0; i < 10000; ++i)
	{
		lock_guard<mutex> lockGuard1(m2);
		lock_guard<mutex> lockGuard2(m1);
	}
}

int main()
{
	thread t1(Thread_1);
	thread t2(Thread_2);

	t1.join();
	t2.join();
}