#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;


/*
给定一个无重复元素的数组，candidates和一个目标数target，找出candidates中所有可以使数字和为target的组合，candidates中的数组可以无限制重复被选取

思路：先使用快排将candidates中的数字从小到大排序，然后
*/

vector<vector<int>> res;
vector<int> temp;

void quicksort(vector<int>& candidates,int start,int end)
{
	if (start == end)
		return;

	int index = (start + end) / 2;
	swap(candidates[index], candidates[end]);
	index = start - 1;
	for (int i = start; i < end; i++)
	{
		if (candidates[i] < candidates[end])
		{
			index++;
			swap(candidates[index], candidates[i]);
		}
	}
	index++;
	swap(candidates[index], candidates[end]);

	if (index > start)
		quicksort(candidates, start, index - 1);
	if (index < end)
		quicksort(candidates, index + 1, end);

}

void dfs(vector<int>& candidates, int target, int index)
{
	if (target == 0)
	{
		res.push_back(temp);
		return;
	}
	else if(target<0)
	{
		return;
	}
	else
	{
		for (int i = index; i < candidates.size(); i++)
		{

			if (target - candidates[i] < 0)
				break;


			temp.push_back(candidates[i]);
			
			cout << "递归之前数组：";
			for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << "\t  剩余：" << target << endl;


			dfs(candidates, target - candidates[i], i);

			cout << "递归之后数组：";
			for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << "\t  剩余：" << target << endl;


			temp.pop_back();
		}
	}

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	dfs(candidates, target,0);
	return res;
}


int main(void)
{
	vector<int> candidates = { 2,3,6,7};
	vector<vector<int>> ans;

	quicksort(candidates, 0, candidates.size() - 1);

	ans = combinationSum(candidates, 7);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

