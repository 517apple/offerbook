#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <ctime> 
#include <windows.h>


using namespace std;

/*
����������
˼·���ݹ����
1. ���ѡȡһ�������ҵ����������������е�λ�ã�ͬʱ���Ը���Ϊ��������Ϊ������С
2. ��ʹ�õݹ�ķ�ʽ
*/

void quicksort(vector<int>& a, int start, int end)
{
	int index = (start+end)/2;
	swap(a[index], a[end]);
	index = start-1;
	for (int i = start; i < end; i++)
	{
		if (a[i] < a[end])
		{
			index++;
			swap(a[index], a[i]);
		}
	}
	index++;
	swap(a[index], a[end]);
	if (index > start)
		quicksort(a, start, index - 1);
	if (index < end)
		quicksort(a, index + 1, end);
}

/*
��������
*/

void insertsort(vector<int>& a)
{
	for (long i = 1; i < a.size(); i++)
	{
		int key = a[i];
		long j = i-1;
		while (j>=0 && a[j]>key)
		{
			swap(a[j], a[j + 1]);
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

	for (long index = 0; index < 100000; index++) {
		a.push_back(rand());
	}

	begin = clock();
	cout << begin << endl;

	//for (int x : a)
	//	std::cout << x << " ";
	//cout << endl;

	//quicksort(a, 0, a.size() - 1);
	insertsort(a);

	clock_t end = clock();
	cout << end << endl;

	//for (int x : a)
	//	std::cout << x << " ";

	std::cout << endl;

	std::cout << "hello world" << endl;
	std::system("pause");
	return 0;

}

