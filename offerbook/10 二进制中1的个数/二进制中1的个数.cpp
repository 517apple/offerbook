#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <math.h>

using namespace std;

/*
自己想的一种解法，可行，不过还有更加简单的方法
*/
int numof1(unsigned int x)
{
	int num = 0;
	while (x > 0)
	{
		unsigned int pow2n = 0, n = 0;
		while (x >= pow2n)
		{
			pow2n = (int)pow(2, n);
			n++;
		}
		++num;
		x = x-(int)pow(2, n - 2);
	}

	return num;

}

/*
简便解法
*/
int numof11(unsigned int x)
{
	int num = 0;
	while (x)
	{
		if (x & 1)
			num++;

		x = x >> 1;
	}
	return num;
}

int main(void)
{
	int a = 0;

	while (true)
	{
		cin >> a;
		if (a == -1)
			break;
		cout << numof1(a)<< "*****"<< numof11(a) << endl;
	
	}
	system("pause");
	return 0;

}

