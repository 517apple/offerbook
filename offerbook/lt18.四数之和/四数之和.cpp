#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>


using namespace std;

/*
https://leetcode-cn.com/problems/4sum/
*/

vector<vector<int>> res;

vector<vector<int>> threeSum(vector<int>& nums,int start, int target) {
	
	int len = nums.size();

	if (len < 3 || nums[start] > target)
		return res;

	for (int i = start; i < len - 1; i++)
	{
		if (nums[i] > target)
			break;

		int l = i + 1, r = len - 1;
		while (l < r)
		{
			long sum = nums[i] + nums[l] + nums[r];
			if (sum > target)
			{
				while (l < r && nums[r] == nums[r - 1])
					r--;
				r--;
			}

			else if (sum < target)
			{
				while (l < r && nums[l] == nums[l + 1])
					l++;
				l++;
			}
			else
			{
				res.push_back({ nums[start - 1], nums[i], nums[l], nums[r] });
				while (l < r && nums[l] == nums[l + 1])
					l++;
				while (l < r && nums[r] == nums[r - 1])
					r--;
				l++;
				r--;
			}
		}
		while (i < len - 1 && nums[i] == nums[i + 1])
			i++;
	}

	return res;
}


vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	if (nums.size() < 4)
		return res;

	for (int i = 0; i < nums.size() - 3; i++)
	{
		threeSum(nums, i + 1, target - nums[i]);
		while (i < nums.size() - 3 && nums[i] == nums[i + 1])
			i++;
	}
	return res;
}


int main(void)
{
	vector<vector<int>> ans;
	//vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<int> nums = { 1, -2, -5, -4, -3, 3, 3, 5 };

	ans = fourSum(nums, 11);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

