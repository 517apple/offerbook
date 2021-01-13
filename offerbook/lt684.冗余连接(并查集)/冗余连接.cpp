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
    //���ﲻ��Ҫ�ٽ���·��ѹ������ΪҪ���ֳ����ľ��ǵ��ߵ��������
    if (a[x] == x)//û�б����Լ�����
        return x;
    else
        return a[x]=find(a[x]);//�ҵ����һ�����Լ����ӵı�
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    for (int i = 0; i <= n; i++)//һ����n+1����
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

