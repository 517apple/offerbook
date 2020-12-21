#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/unique-paths/
*/




/*
下面这种解法思路好清晰！！

下面这个知识点是之前没有接触到的：用vector容器来表示二维数组
vectro<int> arr(5,0);   <==>  [0,0,0,0,0]
vectro<vectro<int>> arr(5,vectro<int>(5,0));
其表现形式应该如下所示：

[0,0,0,0,0]
[0,0,0,0,0]
[0,0,0,0,0]
[0,0,0,0,0]
[0,0,0,0,0]

所以使用arr[0][0]这种类似于二维数组的访问形式在这里也是方便的

*/

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m - 1][n - 1];

}



int mm, nn, ans = 0;
void helper(int m, int n)
{
    cout << m << ":" << n << endl;
    if (m == mm && n == nn)
    {
        ans++;
        return;
    }
    if (m < mm)
        helper(++m, n);
    if (n < nn)
        helper(m, ++n);
}


int uniquePaths2(int m, int n) {
    mm = m;
    nn = n;
    helper(1, 1);

    return ans;
}

//递归解法会超时
int uniquePaths1(int m, int n) {
    if (m == 1 || n == 1) {
        return 1;
    }
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}


int main(void)
{
    uniquePaths2(7, 3);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

