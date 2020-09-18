#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


vector<int> majorityElement1(vector<int>& nums) {

	
	unordered_map<int, int> mymap;
	vector<int> res;
	int len = nums.size();
	if (len < 3)
		return res;

	for (size_t i = 0; i < len; i++)
	{
		mymap[nums[i]] = 0;
	}
	for (size_t i = 0; i < len; i++)
	{
		mymap[nums[i]] ++;
		mymap[nums[i]] ++;
		if (mymap[nums[i]] > len / 3 && mymap[nums[i]] < len + 1)
		{
			res.push_back(nums[i]);
			mymap[nums[i]] = len + 1;
		}
	}
	return res;
}

vector<int> majorityElement(vector<int>& nums) {

	vector<int> res;
	int len = nums.size();
	sort(nums.begin(), nums.end());

	for (int i = 0; i < len; i++)
	{
		int x = 0;
		while (i < len - 1 && nums[i]==nums[i+1])    //此处在顺序这里犯了错误！！
		{
			x++;
			i++;
		}
		x++;
		if (x>len/3)
		{
			res.push_back(nums[i]);
		}
	}
	return res;
}


int main(void)
{
	vector<int> nums = { 1, 1, 1, 3, 3, 2, 2, 2 };
	vector<int> ans = majorityElement(nums);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

