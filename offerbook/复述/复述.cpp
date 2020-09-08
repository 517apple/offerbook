#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

void quicksort(vector<int>& a, int start, int end)
{
	if (start==end)
		return;

	int index = (start + end) / 2;
	swap(a[index], a[end]);
	index = start - 1;
	for (int i = start; i < end; i++)
	{
		if (a[i] < a[end])
		{
			index++;
			swap(a[i], a[index]);
		}	
	}
	index++;
	swap(a[index], a[end]);

	if (index > start)
		quicksort(a, start, index - 1);
	if (index < end)
		quicksort(a, index+1, end);

}

void quicksort_array(int a[],int start,int end)
{
	if (start == end)
		return;
	int index = (start + end) / 2;
	swap(a[index], a[end]);
	index = start - 1;
	for (int i = start; i < end; i++)          //!!!!!!!!此处i的初始值是start
	{
		if (a[i] < a[end])
		{
			index++;
			if(i!=index)
				swap(a[index], a[i]);
		}
	}
	index++;
	swap(a[index], a[end]);

	if (index > start)
		quicksort_array(a, start, index - 1);
	if (index < end)
		quicksort_array(a, index + 1, end);

}


vector<int> topKFrequent(vector<int>& nums, int k) {
	quicksort(nums, 0, nums.size()-1);
	vector<int> tarvec;
	int i = 0, j = 1;

	return nums;
}


int main(void)
{
	int a[5] = { 5,4,3,2,1};
	vector<int> nums = { 1,4,2,7,6 };

	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	quicksort_array(a, 0, 4);

	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	//cout << "--------------分割线-------------" << endl;

	//quicksort(nums, 0, nums.size() - 1);
	//for (size_t i = 0; i < nums.size(); i++)
	//{
	//	cout << nums[i] << " ";
	//}
	//cout << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

