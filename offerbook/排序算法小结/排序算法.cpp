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

/*
归并排序
参考：https://zhuanlan.zhihu.com/p/124356219
动图很形象
*/

void merge_sort_recursive(vector<int>& a, vector<int>& arr, int start,int end)
{
	if (start >= end)
		return;
	int len = end - start, mid = start + (len >> 1);//有待商榷
	int start1 = start, end1 = mid;
	int start2 = mid+1, end2 = end;

	merge_sort_recursive(a, arr, start1, end1);
	merge_sort_recursive(a, arr, start2, end2);

	int k = start;
	while (start1 <= end1 && start2 <= end2)
		arr[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	while (start1 <= end1)
		arr[k++] = a[start1++];
	while (start2 <= end2)
		arr[k++] = a[start2++];

	for (k = start; k <= end; k++)
		a[k] = arr[k];

}



void partition(vector<int>& a, vector<int>& arr, int start, int end)
{
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	int start1 = start, end1 = mid;
	int start2 = mid+1, end2 = end;
	partition(a, arr, start1, end1);
	partition(a, arr, start2, end2);

	int k = start;
	while (start1 <= end1 && start2 <= end2)
		arr[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	while (start1 <= end1)
		arr[k++] = a[start1++];
	while (start2 <= end2)
		arr[k++] = a[start2++];

	for (int i = start; i <= end; i++)
		a[i] = arr[i];

}



void merge_sort(vector<int>& a)
{
	int len = a.size();
	vector<int> arr(len);
	//merge_sort_recursive(a, arr, 0, len - 1);
	partition(a, arr, 0, len - 1);
}



/*
快速排序

*/

void Partition(vector<int>& a, int start, int end)
{
	if (start >= end)
		return;
	int index = (start + end) / 2;
	swap(a[index], a[end]);
	index = start - 1;
	for (int i = start; i < end; i++)
	{
		if (a[i] < a[end])
			swap(a[++index], a[i]);
	}
	swap(a[++index], a[end]);
	
	if(index>start)
		Partition(a, start, index - 1);
	if(end>index)
		Partition(a, index + 1, end);

}

void quicksort(vector<int>& a)
{
	Partition(a, 0, a.size()-1);
}


/*
* 1 2 3 4 5
*/
void insertsort1(vector<int>& a)
{
	int len = a.size();
	for (int i = 1; i < len; i++)
	{
		int val = a[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (a[j] > val)
			{
				a[j + 1] = a[j];
				continue;
			}
			break;
		}
		a[j + 1] = val;
	}

}


/*
* 计数排序
*/

void countingSort(vector<int>& a,int maxval)
{
	int len = a.size();
	vector<int> temp(maxval+1, 0);
	for (int i = 0; i < len; i++)
		temp[a[i]]++;
	int index = 0;
	for (int i = 0; i <= maxval; i++)
	{
		while (temp[i])
		{
			a[index++] = i;
			temp[i]--;
		}
	}
}

int main(void)
{
	vector<int> a;

	int i = 1,j=2;
	i += j + j;

	clock_t begin = clock();
	cout << begin << endl;

	for (long index = 0; index < 15; index++) {
		a.push_back(rand()%20);
	}

	begin = clock();
	cout << begin << endl;

	for (int x : a)
		std::cout << x << " ";
	cout << endl;

	//insertsort1(a);
	//quicksort(a);
	//bubbleSort(a);
	//selectSort(a, 0);
	//insertSort(a);
	//merge_sort(a);
	countingSort(a, 20);

	for (int x : a)
		std::cout << x << " ";
	cout << endl;

	clock_t end = clock();
	cout << end-begin<< "ms" << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

