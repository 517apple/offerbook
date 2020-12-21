#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;


/*
https://leetcode-cn.com/problems/triangle/
*/


void dfs(vector<vector<int>>& triangle, int x, int y, int sum, int& ans)
{
	if (x == triangle.size())
	{
		ans = min(ans, sum);
		return;
	}
			
	dfs(triangle, x + 1, y, sum + triangle[x][y], ans);
	dfs(triangle, x + 1, y+1, sum + triangle[x][y], ans);

}


int minimumTotal1(vector<vector<int>>& triangle) {
	if (triangle.size() == 0)
		return 0;
	int sum = 0;

}

int mymin(int a, int b, int c)
{
    int x = a < b ? a : b;
    int y = x < c ? x : c;
    return y;
}


//原地算法，自己想出来的
int minimumTotal(vector<vector<int>>& triangle) {
    int len = triangle.size();
    if (len == 0)
        return 0;

    cout << triangle[0][0] << " ";
    cout << endl;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            //正常来说都会有三条路径，这里定义三个变量a/b/c如果不存在，则定义成最大值
//这里把题意理解错误了，只有a,b,没有c
            int a = (j - 1) < 0 ? INT_MAX : triangle[i - 1][j - 1];
            int b = j > i - 1 ? INT_MAX : triangle[i - 1][j];
            //int c=(j+1)>i-1?INT_MAX:triangle[i-1][j+1];
            //cout<<a<<"     :     "<<b<<"      :      "<<c<<"     :      "<<endl;
            //cout<<"--------------"<<mymin(a,b,c)<<endl;
            triangle[i][j] = ((min(a, b) == INT_MAX) ? 0 : min(a, b)) + triangle[i][j];
        }

        for (auto x : triangle[i])
            cout << x << " ";
        cout << endl;

    }
    int minsum = triangle[len - 1][0];

    for (auto x : triangle[len - 1])
        minsum = min(minsum, x);
    return minsum;
}


//这里是更加简洁的代码,思路一致，比我的代码简洁而且高效
int minimumTotal(vector<vector<int>>& triangle) {
    int len = triangle.size();
    if (len == 0)
        return 0;

    for (int i = len - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }
    return triangle[0][0];
}

int main(void)
{
    vector<vector<int>> triangle = { {-1}, {3, 2}, {-3, 1, -1} };
    minimumTotal(triangle);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

