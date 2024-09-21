#include <iostream>
using namespace std;

// OOP 3�� ���
// - ��Ӽ� << inher itance
// - ���м� << data hiding (ĸ��ȭ encapsulation)
// - ������ << polymorphism (poly + morphism)

// �����ε�(overloading) = �Լ� �̸��� ����
// �������̵�(overriding) = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// vftable(virtual function table) [ �ּ�1 | �ּ�2 | �ּ�3 ]

// �߻� Ŭ����
class Player
{
public:
	virtual void Move() = 0;	// ���� ���� �Լ�
	// virtual void Move() abstract;
public:
	int _hp = 0;
};

class Knight : public Player
{
public:
	virtual void Move() override { cout << "Knight Move()" << endl; }
public:
	int _stamina = 200;
};

// ���ε�(Binding) = ���´�
// - ���� ���ε� (static binding = ������ ���� ����)
// - ���� ���ε� (dynamic binding = ���� ���� ����)
void MovePlayer(Player* player)
{
	player->Move();
}

int main()
{
	Knight k1;
	k1.Move();
	MovePlayer(&k1);

	//Player p1;
}