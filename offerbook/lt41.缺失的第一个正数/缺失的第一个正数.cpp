#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*

https://leetcode-cn.com/problems/first-missing-positive/

思路：
1、 找到最大的那个
*/


int firstMissingPositive(vector<int>& nums) {
	int len = nums.size();
	if (len == 0)
		return 1;
	int maxval = 1;
	for (int i = 0; i < len; i++)
	{
		maxval = maxval > nums[i] ? maxval : nums[i];
	}
	return maxval = 1;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

