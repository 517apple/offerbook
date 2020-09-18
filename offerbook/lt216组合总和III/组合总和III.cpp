#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
https://leetcode-cn.com/problems/combination-sum-iii/

QAQ：使用vector时访问越界的原因还没有找到
*/

vector<int> nums = { 1,2,3,4,5,6,7,8,9 };

vector<vector<int>> res;
vector<int> temp;

void dfs(int index,int k, int target)
{
	if (target == 0 && k==0)
	{
		res.push_back(temp);
		return;
	}
	if (target-index < 0 || k==0)
		return;

	for (int i = index; i <= 9; i++)
	{
		//剪枝
		if (target - i < 0)
			break;
		temp.push_back(i);
		dfs(i + 1, k - 1, target - i);
		temp.pop_back();
	}
}


void dfs1(int index, int k, int target)
{
	if (target == 0 && k == 0)
	{
		res.push_back(temp);
		return;
	}
	if (target < 0 || k == 0)
		return;

	for (int i = index; i < 9; i++)
	{
		//剪枝
		if (target - nums[i] < 0)
			break;

		temp.push_back(nums[i]);

		cout << "递归之前数组：";
		for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\t  剩余：" << target << endl;

		dfs1(i + 1, k - 1, target - nums[i]);

		cout << "递归之后数组：";
		for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\t  剩余：" << target << endl;

		temp.pop_back();
	}
}



vector<vector<int>> combinationSum3(int k, int n) {
	dfs1(0, k, n);
	return res;
}


int main(void)
{
	vector<vector<int>> ans;
	ans = combinationSum3(3, 15);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

