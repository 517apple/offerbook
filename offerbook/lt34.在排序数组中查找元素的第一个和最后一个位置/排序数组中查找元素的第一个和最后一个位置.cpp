#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

思路：
1. 使用二分查找法在数组中进行查找，确定在数组中存在该值
2. 若没有找到，返回-1；若找到，则返回索引
3. 在索引的前后进行查找，确定前后界
*/


int index = -1;

int findval(vector<int>& nums, int target,int start,int end)
{
	if (end > start)
	{
		int mid = (start + end) / 2;
		if (nums[mid] < target)
		{
			findval(nums, target, mid + 1, end);
		}
		else if (nums[mid] > target)
		{
			findval(nums, target, start, mid - 1);
		}
		else
		{
			index = start + end / 2;
			return index;
		}
	}
	
	return index;
}



vector<int> searchRange(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> res = { -1,-1 };
	if (len == 0 || target<nums[0])
		return res;

	findval(nums, target, 0, len - 1);

	if (index == -1)
		return res;

	int left, right;
	left = right = index;
	while (left > 0 && nums[left] == nums[left - 1])
		left--;
	if (nums[0] == target)
		left = 0;

	while (right <len-1  && nums[right] == nums[right + 1])
		right++;
	if (nums[len-1] == target)
		right = len-1;

	res[0] = left;
	res[1] = right;

	return res;
}


/*
下面这个是参考的题解
思路是理由一个while循环寻找边界，没有利用迭代的方法

这个解法还没有真正理解
*/



vector<int> searchRange1(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> res = { -1,-1 };
	if (len == 0 || target < nums[0])
		return res;

	int l = 0, r = len - 1;
	//寻找左边界，
	while (r>l)
	{
		int m = (l + r) / 2;
		if (nums[m] >= target)
			r = m;
		else
			l = m + 1;
	}

	if (nums[l] != target)
		return res;

	res[0] = l;
	r = len-1;

	//寻找右边界
	while (r > l)
	{
		int m = (l + r) / 2;
		if (nums[m] <= target)
			l = m;
		else
			r = m-1;
	}

	res[1] = r;

	return res;
}




int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

