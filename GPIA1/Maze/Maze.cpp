#include <iostream>
#include "Array.h"
#include "Vector.h"

int main()
{
	Array arr(100);

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	arr[1] = 2;

////////////////////////////////////////

	Vector v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	int a = v[1];
}