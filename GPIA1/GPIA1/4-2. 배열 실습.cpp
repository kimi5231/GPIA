#include <iostream>
#include "4-2. Helper.h"
#include "4-2. Map.h"
#include "4-2. Player.h"
using namespace std;

int main()
{
	SetCursorOnOff(false);

	while (true)
	{
		// �Է�
		HandleKeyInput(); 

		// ����
		HandleMove2D();

		// ���
		PrintMap2D();
	}
	
}