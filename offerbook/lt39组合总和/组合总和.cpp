#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;


/*
����һ�����ظ�Ԫ�ص����飬candidates��һ��Ŀ����target���ҳ�candidates�����п���ʹ���ֺ�Ϊtarget����ϣ�candidates�е���������������ظ���ѡȡ

˼·����ʹ�ÿ��Ž�candidates�е����ִ�С��������Ȼ��
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
			temp.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i);
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
	vector<int> candidates = { 7,6,1,3,2};
	vector<vector<int>> ans;

	quicksort(candidates, 0, candidates.size() - 1);

	ans = combinationSum(candidates, 7);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

