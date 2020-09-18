#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�
https://leetcode-cn.com/problems/combination-sum-iii/

QAQ��ʹ��vectorʱ����Խ���ԭ��û���ҵ�
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
		//��֦
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
		//��֦
		if (target - nums[i] < 0)
			break;

		temp.push_back(nums[i]);

		cout << "�ݹ�֮ǰ���飺";
		for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\t  ʣ�ࣺ" << target << endl;

		dfs1(i + 1, k - 1, target - nums[i]);

		cout << "�ݹ�֮�����飺";
		for (vector<int>::iterator iter = temp.begin(); iter < temp.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\t  ʣ�ࣺ" << target << endl;

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

