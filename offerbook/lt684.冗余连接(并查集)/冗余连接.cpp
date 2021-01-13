#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/redundant-connection/

*/

vector<int> a;

int find(int x)
{
    //这里不需要再进行路径压缩，因为要体现出来的就是单边的连接情况
    if (a[x] == x)//没有边与自己连接
        return x;
    else
        return a[x]=find(a[x]);//找到最后一条与自己连接的边
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    for (int i = 0; i <= n; i++)//一共有n+1条边
        a.push_back(i);
    vector<int> ans(2, 0);
    /*
    [1 2]  0 2 0 0 
    [1 3]  0 2 3 0
    [2 3]  0 2 3 0
    */
    for (int i = 0; i < n; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        int x1 = find(x);
        int y1 = find(y);
        if (x1 == y1)
        {
            ans[0] = x;
            ans[1] = y;
        }
        else
            a[x1] = y1;
    }
    return ans;
}

int main(void)
{
    vector<vector<int>> edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
    findRedundantConnection(edges);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

