#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode-cn.com/problems/pond-sizes-lcci/

*/


int dfs(vector<vector<int>>& land,int i,int j)
{
	if (i<0 || i>=land.size() || j<0 || j>=land[0].size())
		return 0;

	if (land[i][j] != 0)
		return 0;

	land[i][j] = 1;//计算过的节点就不必要计算了

	int cnt = 1;

	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			if(!(x==0 && y==0))
				cnt += dfs(land, i + x, j + y);
		}
	}
	return cnt;
}

vector<int> pondSizes(vector<vector<int>>& land) {
	vector<int> ans;
	if (land.size() == 0)
		return ans;

	for (int i = 0; i < land.size(); i++)
	{
		for (int j = 0; j < land[0].size(); j++)
		{
			if (land[i][j] == 0)
			{
				int cnt = dfs(land, i, j);
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());

	return ans;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

