#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <ctime>


using namespace std;


/*
https://www.cnblogs.com/onepixel/articles/7674659.html


*/


/*
冒泡排序
两两比较交换能够找出最大（小）的元素
*/
void bubbleSort(vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size() - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

/*
选择排序

*/
void selectSort(vector<int>& a,int start)
{
	if (start >= a.size())
		return;

	int index = start;
	for (int i = start+1; i < a.size(); i++)
	{
		if (a[index] < a[i])
			index = i;
	}
	swap(a[index], a[start]);
	selectSort(a,start + 1);
}

/*
插入排序

*/
void insertSort(vector<int>& a)
{
	for (long i = 1; i < a.size(); i++)
	{
		int key = a[i];
		long j = i - 1;
		while (j>=0 && a[j]>key)
		{
			swap(a[j + 1], a[j]);
			j--;
		}
		a[j + 1] = key;
	}
}



int main(void)
{
	vector<int> a;

	clock_t begin = clock();
	cout << begin << endl;

	for (long index = 0; index < 11; index++) {
		a.push_back(rand()%100);
	}

	begin = clock();
	cout << begin << endl;

	for (int x : a)
		std::cout << x << " ";
	cout << endl;

	//quicksort(a, 0, a.size() - 1);
	//bubbleSort(a);
	//selectSort(a, 0);
	insertSort(a);

	for (int x : a)
		std::cout << x << " ";
	cout << endl;

	clock_t end = clock();
	cout << end << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

