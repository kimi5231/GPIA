#include <iostream>
using namespace std;

// ������ �����ε�

// - ��� ������ �Լ� ����
// -- a op b ���¿��� ������ �������� ����

// - ���� ������ �Լ� ����
// -- a op b ���¶��, a/b ��θ� ������ �Լ��� �ǿ����ڷ� ���
class Pos
{
public:
	Pos()
	{

	}

	explicit Pos(int b)
	{
		x = b;
		y = b;
	}

	Pos operator+(const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;
		return pos;
	}

	Pos operator+(const int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;
		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	//���� ������
	Pos& operator=(const int b)
	{
		x = b;
		y = b;
		return *this;
	}

	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	Pos pos1(10);
	Pos pos2(20);

	// ����
	pos1 = 10;
	pos2 = 20;
}