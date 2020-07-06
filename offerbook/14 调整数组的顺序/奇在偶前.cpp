#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
自写，原始版本
*/
void ReorderOddEven(int* pData, unsigned int length)
{
	if (pData == NULL || length < 0)
		return;

	int* p1 = pData, * p2 = pData + length;
	while (p2>p1)
	{
		if (*p1 % 2)
			p1++;
		if (*p2 % 2 == 0)
			p2--;

		if (*p1 % 2 == 0 && *p2 % 2 == 1)
		{
			swap(*p1, *p2);
			p1++; p2--;
		}
	}
}

/*
修改完善后的版本
*/
void ReorderOddEven1(int* pData, unsigned int length)
{
	if (pData == NULL || length == 0)
		return;

	int* p1 = pData, * p2 = pData + length-1;   //可以直接代入一种情况进行验证
	while (p2 > p1)
	{
		//判断奇偶数不用 %2 取余了，使用 &0x1
		while ((*p1 & 0x1) != 0)
			p1++;
		while ((*p2 & 0x1) == 0)
			p2--;

		swap(*p1, *p2);
		 
	}
}


int main(void)
{
	int a1[7] = { 1,2,7,5,9,2,8 };
	int a[21];

	srand(NULL);
	for (size_t i = 0; i < 21; i++)
	{
		a[i] = rand() % 100;
	}

	ReorderOddEven(a, sizeof(a) / sizeof(int));

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d  ", a[i]);
	}

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

