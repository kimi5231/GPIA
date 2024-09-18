#include <iostream>
using namespace std;

int StrLen(const char* str)
{
	int count = 0;

	// 0 == '\0'
	while (str[count] != 0)
		count++;

	return count;
}

char* StrCpy(char* dest, char* src)
{
	char* ret = dest;

	/*int i = 0;

	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;*/

	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = 0;

	return ret;
}

char* StrCat(char* dest, char* src)
{
	char* ret = dest;

	int len = StrLen(dest);

	/*int i = 0;
	while (src[i] != 0)
	{
		dest[len + i] = src[i];
		i++;
	}

	dest[len + i] = 0;*/

	dest += len;

	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = 0;

	return ret;
}

int main()
{
	char ch = 'A';
	cout << ch << endl;

	char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	cout << str1 << endl;

	char str2[] = "Hello";
	cout << str2 << endl;

	const char* ptr = "Hello";
	ptr = nullptr;

	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	int len = strlen(a);
	cout << len << endl;

#pragma warning(disable:4996)
	char c[BUF_SIZE];
	//strcpy(c, a);
	StrCpy(c, a);
	cout << c << endl;

	//cout << strcat(a, b) << endl;
	cout << StrCat(a, b) << endl;
}