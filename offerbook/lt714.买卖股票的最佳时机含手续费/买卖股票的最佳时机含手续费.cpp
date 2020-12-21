#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/


*/

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> f(2);
    // 0 : 不持股   1 : 持股
    f[0] = 0;
    f[1] = -prices[0];
    for (int i = 1; i < n; i++) {
        f[0] = max(f[0], f[1] + prices[i] - fee);
        f[1] = max(f[1], f[0] - prices[i]);
        cout << prices[i] <<":"<< f[0] << ":" << f[1] << endl;
    }
    return f[0];
}

int main(void)
{
    vector<int> a = { 1,3,2,8,4,9 };
    maxProfit(a, 2);

    int m = 2,n = 3;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));



	cout << "hello world" << endl;
	system("pause");
	return 0;

}

