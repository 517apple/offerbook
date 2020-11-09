#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/count-of-range-sum/


*/


int countRangeSum(vector<int>& nums, int lower, int upper) {
	int ans = 0, length = nums.size();
	for (size_t i = 0; i < length; i++)
	{
		long sum = nums[i];
		for (size_t j = i+1; j < length; j++)
		{
			if (sum >= lower && sum <= upper)
				ans++;
			sum += nums[j];
		}
	}
	return ans;
}



int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

