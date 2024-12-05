#include <iostream>

using namespace std;

class Knight : public enable_shared_from_this<Knight>
{
public:
	void Test()
	{
		Move(shared_from_this());
	}

	void Move(shared_ptr<Knight> k)
	{

	}
};

int main()
{
	shared_ptr<Knight> k(new Knight());
	k->Test();
}