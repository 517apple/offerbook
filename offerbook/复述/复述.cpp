#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


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



int main(void)
{
	vector<int> a = { 5,4,3,2,1,-2 };

	char ch;
	cin >> ch;
	while (ch!=-1)
	{
		a.push_back((int)ch);
		cin >> ch;
	}
	quicksort(a, 0, a.size() - 1);
	for (int x : a)
		cout << x << " ";

	cout << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

