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
		// 입력
		HandleKeyInput(); 

		// 로직
		HandleMove2D();

		// 출력
		PrintMap2D();
	}
	
}