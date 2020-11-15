#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	map<int, int> mymap;
	vector<int> res;
	for (auto x : arr1)
	{
		if (mymap.find(x) == mymap.end())
		{
			mymap.insert(make_pair(x, 1));
		}
		else
		{
			mymap[x]++;
		}
	}

	for (auto x : arr2)
	{
		while (mymap[x])
		{
			res.push_back(x);
			mymap[x]--;
		}
		mymap.erase(x);
	}

	for (auto iter = mymap.begin(); iter != mymap.end(); iter++)
	{
		//cout << iter->first << ": " << iter->second << endl;
		int x = iter->first;
		while (mymap[x])
		{
			res.push_back(x);
			mymap[x]--;
		}
		//mymap.erase(x);
	}

	return res;
}


vector<int> relativeSortArray1(vector<int>& arr1, vector<int>& arr2) {
	//可以利用题目中的限制条件使用数组的方式来做题
	vector<int> res;
	vector<int> nums1(1001, 0);
	for (auto x : arr1)
		nums1[x]++;
	for (auto x : arr2)
	{
		while (nums1[x]--)
			res.push_back(x);
	}
	for (int i = 0; i < 1001; i++)
	{
		int x = nums1[i];
		if (x == 0)
			continue;
		else
		{
			for (int j = 0; j < x; j++)
				res.push_back(i);
		}
	}


	return res;
}

int main(void)
{
	vector<int> arr1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
	vector<int> arr2 = { 2, 1, 4, 3, 9, 6 };
	//relativeSortArray1(arr1,arr2);

	for (auto& x : arr1)
		x++;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

