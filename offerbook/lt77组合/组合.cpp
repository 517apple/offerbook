#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
������������n��k������1,,,n�����п��ܵ�k���������
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
    ans = combine(4, 3);

    

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

