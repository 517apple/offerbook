#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

˼·��
1. ʹ�ö��ֲ��ҷ��������н��в��ң�ȷ���������д��ڸ�ֵ
2. ��û���ҵ�������-1�����ҵ����򷵻�����
3. ��������ǰ����в��ң�ȷ��ǰ���
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
��������ǲο������
˼·������һ��whileѭ��Ѱ�ұ߽磬û�����õ����ķ���

����ⷨ��û���������
*/



vector<int> searchRange1(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> res = { -1,-1 };
	if (len == 0 || target < nums[0])
		return res;

	int l = 0, r = len - 1;
	//Ѱ����߽磬
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

	//Ѱ���ұ߽�
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

