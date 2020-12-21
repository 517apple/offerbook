#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/longest-increasing-subsequence/

*/


int lengthOfLIS(vector<int>& nums) {
    int len = nums.size(), ans = 0;;
    vector<vector<int>> dp(len, vector<int>(2, 0));//第一个元素代表上一个数的数值，第二个数代表前面已有序列的个数

    for (int i = 0; i < len; i++)
    {
        dp[i][0] = nums[i];
        dp[i][1] = 1;
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j][0] < nums[i])
            {
                dp[j][0] = nums[i];
                dp[j][1]++;
                ans = max(ans, dp[j][1]);
            }
        }
    }
    return ans;
}

int lengthOfLIS1(vector<int>& nums) {
    int len = nums.size(), ans = 0;;
    vector<int> dp(len, 1);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main(void)
{
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    lengthOfLIS1(nums);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

