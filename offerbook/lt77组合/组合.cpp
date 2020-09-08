#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
给定两个整数n和k，返回1,,,n中所有可能的k个数的组合
*/

vector<vector<int>> res;
vector<int> temp;

void dfs(int n, int k, int index)
{
    if (k == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = index; i <= n; i++)
    {
        temp.push_back(i);
        dfs(n, k - 1, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    dfs(n, k, 1);
    return res;
}

int main(void)
{
    vector<vector<int>> ans;
    ans = combine(4, 2);

    

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

