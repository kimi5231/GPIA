#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void HelloThread(int i)
{
    cout << "Hello Thread " << i << endl;
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 10; ++i)
    {
        // 인자 넘겨주기도 가능.
        threads.push_back(thread(HelloThread, i));
    }

    cout << "Hello World" << endl;
    
    // 쓰레드 실행이 완료될 때까지 기다림.
    for (thread& t : threads)
    {
        t.join();
    }
}