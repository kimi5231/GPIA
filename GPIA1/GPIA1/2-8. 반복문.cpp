#include <iostream>
using namespace std;

int cnt;

int main()
{
	// while
	// for
	// do-while

	cnt = 0; 

	while (cnt < 5)
	{
		cout << "Hello World" << endl;
		cnt++;
		if (cnt == 3)
			break;
	}
	
	for (int i = 0; i < 100; ++i)
	{
		cout << "Hello World" << endl;
		if (i == 50)
			continue;
	}
}