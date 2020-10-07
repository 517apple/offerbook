#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
https://leetcode-cn.com/problems/sort-colors/


*/


/*
解法1： 一次遍历之后找出0，1，2的个数，数组空了之后再重新push进数组
*/
void sortColors(vector<int>& nums) {
	int i, j, k;
	i = j = k = 0;
	int len = nums.size();
	while (!nums.empty())
	{
		int n = nums.back();
		switch (n)
		{
			case 0:i++; break;
			case 1:j++; break;
			case 2:k++; break;
			default:
				break;
		}
		nums.pop_back();
	}

	while (i--)
		nums.push_back(0);
	while (j--)
		nums.push_back(1);
	while (k--)
		nums.push_back(2);

}

/*
搬移数组会对数组产生影响，这一点暂时没有想到如何解决
*/
void sortColors(vector<int>& nums) {
	int len = nums.size();
	int i = 0, j = len-1;//分别表示0或2的个数，用于找到对应的数字之后进行交换

	for (int k = 0; k < len; k++)
	{
		int n = nums[k];
		switch (n)
		{
			case 0:swap(nums[i], nums[k]); i++; break;
			case 2:swap(nums[j], nums[k]); j--; break;
			default:
				break;
		}
	}

}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

