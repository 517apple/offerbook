#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
给定一个没有重复数字的序列，返回其所有可能的全排列
answer:https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
*/

void dfs(vector<vector<int>>& res, vector<int>& output, int first, int len)
{
	if (first == len)
	{
		res.push_back(output);
		return;
	}

	for (int i = first; i < len; i++)
	{
		swap(output[i], output[first]);
		dfs(res, output, first + 1, len);
		swap(output[i], output[first]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	dfs(res, nums, 0, nums.size());
	return res;
}


int main(void)
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res;
	res = permute(nums);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

