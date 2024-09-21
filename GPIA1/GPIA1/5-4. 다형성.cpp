#include <iostream>
using namespace std;

// OOP 3대 요소
// - 상속성 << inher itance
// - 은닉성 << data hiding (캡슐화 encapsulation)
// - 다형성 << polymorphism (poly + morphism)

// 오버로딩(overloading) = 함수 이름의 재사용
// 오버라이딩(overriding) = 부모 클래스의 함수를 자식 클래스에서 재정의

// vftable(virtual function table) [ 주소1 | 주소2 | 주소3 ]

// 추상 클래스
class Player
{
public:
	virtual void Move() = 0;	// 순수 가상 함수
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

// 바인딩(Binding) = 묶는다
// - 정적 바인딩 (static binding = 컴파일 시점 결정)
// - 동적 바인딩 (dynamic binding = 실행 시점 결정)
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