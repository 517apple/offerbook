#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
¿ìËÙÅÅĞò
*/

int Pratition(int data[], int start, int end)
{
	if (data == NULL || start<0 || start>end)
		return -1;

	int index = (start + end) / 2;
	swap(data[index], data[end]);
	index = start - 1;
	for (size_t i = start; i < end; i++)
	{
		if (data[i] < data[end])
		{
			++index;
			if (data[i] != data[index])
				swap(data[i], data[index]);
		}
	}
	++index;
	swap(data[index], data[end]);

	return index;

}

void QuickSort(int data[], int start, int end)
{
	if (data == NULL || start<0 || start>end)
		return ;

	int index = Pratition(data , start, end);

	if (index > start)
		QuickSort(data, start, index - 1);
	if(index<end)
		QuickSort(data, index + 1,end);

}


int main(void)
{
	int a[7] = { 1,2,7,5,9,2,8 };
	QuickSort(a, 3, 6);

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d  ", a[i]);
	}

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

