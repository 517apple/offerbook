#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>


using namespace std;

/*
https://leetcode-cn.com/problems/3sum-closest/

小结：在这个题目当中犯了两个错误：
1. 审题不够细致，在计算两个数的差值的时候没有使用绝对值
2. 在coding的时候思路也没有理顺，在pright--的条件上犯了错误
*/


int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int sum = nums[0] + nums[1] + nums[2];
	int mindiff = abs(target - sum);
	int length = nums.size();
	for (int i = 0; i < length; i++)
	{
		int pleft = i + 1, pright = length - 1;
		int sum1 = 0;
		while (pright>pleft)
		{
			sum1 = nums[i] + nums[pleft] + nums[pright];
			if (abs(target - sum1) < mindiff)
			{
				sum = sum1;
				mindiff = abs(target - sum);
				if (mindiff == 0)
					return sum;
			}
			if (target < sum1)
				pright--;
			else
				pleft++;
		}
	}
	return sum;
}



int main(void)
{
	vector<int> a = { 0,2,1,-3 };
	int sum = threeSumClosest(a, 1);

	cout << sum << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

