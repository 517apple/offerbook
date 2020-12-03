#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
https://leetcode-cn.com/problems/make-sum-divisible-by-p/

*/


int minSubarray(vector<int>& nums, int p) {
    int len = nums.size();
    if (len == 0)
        return -1;
    int sum = 0;
    for (int x : nums)
        sum += x;
    if (sum % p == 0)
        return 0;

    /*
    len=4;
    i=1;  j=0;  j<=3;
    j+num-1:
    i max = 3;
    */
    for (int i = 1; i < len; i++)//子数组的长度
    {
        for (int j = 0; j <= len - i; j++)
        {
            int num = i, tempsum = 0;
            while (num--)
            {
                tempsum += nums[j + num - 1];
            }
            if ((sum - tempsum) % p == 0)
                return i;
        }
    }
    return -1;
}

int main(void)
{
    vector<int> nums = { 3,1,4,2 };
    minSubarray(nums, 6);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

