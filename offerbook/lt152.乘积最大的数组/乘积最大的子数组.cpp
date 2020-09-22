#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
using namespace std;

/*
https://leetcode-cn.com/problems/maximum-product-subarray/

for循环，循环

如果乘积是0了，就可以结束当前循环了

*/


int maxProduct(vector<int>& nums) {
	int len = nums.size();
	if (len == 1)
		return nums[0];

	int res = nums[0];

	for (int i = 0; i < len; i++)
	{
		int v1 = nums[i];
		if (v1 > res)
			res = v1;
		for (int j = i+1; j < len; j++)
		{
			v1 *= nums[j];
			if (v1 > res)
				res = v1;
			if (v1 == 0)
				break;
		}
	}
	return res;
}


int maxProduct(vector<int>& nums) {
	int len = nums.size();
	int maxval = nums[0],maxval2=nums[len-1];

	//有0或者负数的个数是偶数个的情况
	int a = 1;
	for (int i = 0; i < len; i++)
	{
		a *= nums[i];

		if (a > maxval)
			maxval = a;
		if (a == 0)
			break;
	}

	//负数的个数是奇数个的情况
	a = 1;
	for (int i = len; i <= 0; i--)
	{
		a *= nums[i];

		if (a > maxval2)
			maxval2 = a;
		if (a == 0)
			break;
	}

	return max(maxval, maxval2);
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

