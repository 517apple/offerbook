#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode-cn.com/problems/next-permutation/

先返回所有的排列组合
*/


void dfs(vector<vector<int>>& res, vector<int>& output, int first, int len)
{
	if (first == len)
	{
		res.push_back(output);
		return;
	}

	for (int i = first; i < len; i++)
	{
		swap(output[i], output[first]);
		dfs(res, output, first + 1, len);
		swap(output[i], output[first]);
	}
}


void nextPermutation(vector<int>& nums) {
    int val = 0, len = nums.size();
    if (len < 2)
        return;
    for (int i = 0; i < len; i++)
        val = val * 10 + nums[i];
    vector<vector<int>> res;
    dfs(res, nums, 0, len);

    vector<int> arr;
    for (auto vec : res)
    {
        int temp = 0;
        for (int i = 0; i < vec.size(); i++)
            temp = temp * 10 + vec[i];
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    while (i < arr.size() && arr[i] <= val)
        i++;
    nums.clear();
    if (i == arr.size())
    {
        val = arr[0];
        int x = pow(10, len - 1);
        while (x)
        {
            nums.push_back((val / x) % 10);
            x /= 10;
        }
    }
    else
    {
        val = arr[i];
        int x = pow(10, len);
        while (x)
        {
            nums.push_back((val / x) % 10);
            x /= 10;
        }
    }

}




int main(void)
{
	vector<int> nums = { 1,2,3 };
	nextPermutation(nums);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

