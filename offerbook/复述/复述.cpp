#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
快速排序  把+号写成了 - 号  。。。。。。
*/
int partion(int a[], int start, int end)
{
	if (a == NULL || end < start)
		return -1;
	int value = a[(end + start) / 2], index = start - 1;
	swap(a[(end + start) / 2], a[end]);
	for (int i = start; i < end; i++)
	{
		if (a[i] < value)
		{
			index++;
			if (a[index] != a[i])
				swap(a[index], a[i]);
		}
	}
	index++;
	swap(a[index], a[end]);
	return index;

}

void QuickSort(int a[], int start, int end)
{
	if (a == NULL || end < start)
		return ;

	int index = partion(a, start, end);
	if (index > start)
		QuickSort(a, start, index - 1);
	if (index < end)
		QuickSort(a, index + 1, end);
}

int main(void)
{
	int a[7] = { 1,2,7,5,9,2,8 };
	QuickSort(a, 0, 6);

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d  ", a[i]);
	}

	cout << a << a + 1 << endl;

	int m=2, n=1;
	cout << &m << endl << &n << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

