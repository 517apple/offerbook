#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

/*
在数组中找到所有可以使数字和为target的组合
每个数字只能使用一次
*/

void quicksort(vector<int>& nums,int start,int end)
{
	if (start == end)
		return;
	int index = (start + end) / 2;
	swap(nums[start], nums[end]);
	index = start - 1;
	for (int i = start; i < end; i++)
	{
		if (nums[i] < nums[end])
		{
			index++;
			swap(nums[i], nums[index]);
		}
	}
	index++;
	swap(nums[index], nums[end]);

	if (index > start)
		quicksort(nums, start, index - 1);
	if (index < end)
		quicksort(nums, index + 1, end);

}

void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int index,int len)
{
	if (target <= 0)
	{
		if (target == 0)
			res.push_back(temp);
		return;
	}

	for (int i = index; i < len; i++)
	{
		if (i > index && candidates[i] == candidates[i - 1])
			continue;

		//大剪枝
		if (target - candidates[i] < 0)
			break;

		cout << "递归之前数组：";
		for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout <<"\t  剩余："<< target << endl;

		temp.push_back(candidates[i]);
		dfs(res, temp, candidates, target - candidates[i], i + 1, len);

		cout << "递归之后数组：";
		for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\t  剩余：" << target << endl;


		temp.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//	quicksort(candidates, 0, candidates.size() - 1);
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> temp;
	dfs(res, temp, candidates, target, 0, candidates.size());

	return res;
}

int main(void)
{
	vector<vector<int>> ans;
	vector<int> nums = { 10,1,2,7,6,1,5 };

	ans = combinationSum2(nums, 8);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

