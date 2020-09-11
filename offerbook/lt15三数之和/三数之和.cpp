#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>


using namespace std;

/*
��Դ��https://leetcode-cn.com/problems/3sum/
*/


/*
1. �Լ��Ľⷨ���̶��м�����Ȼ������ָ���ƶ���
Ŀǰȥ��û�н����Ŀǰ�����Ļ���ΪʲôҪ�̶��м��������أ��̶���һ����Ч������һ����QAQ
*/
vector<vector<int>> threeSum1(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<vector<int>> res;

	if (nums.size() < 3 || nums[0]>0)
		return res;

	for (int m = 1; m < nums.size()-1; m++)
	{
		if ((nums[m] == nums[m - 1]) && m>1)
			m++;

		int l = 0, r = nums.size() - 1;

		while (l<m || r>m)
		{
			
			int sum = nums[l] + nums[m] + nums[r];

			

			if (sum == 0)//����ָ��ͬʱ�ƶ�һλ
			{
				vector<int> temp;
				temp.push_back(nums[l]);
				temp.push_back(nums[m]);
				temp.push_back(nums[r]);
				res.push_back(temp);

				while (r > m + 1 && nums[r] == nums[r - 1])
					r--;
				while (l < m - 1 && nums[l] == nums[l + 1])
					l++;


				if (r > m + 1)
					r--;
				if (l < m - 1)
					l++;
			}
			else if (sum>0)//��ָ�������ƶ�һλ
			{
				if (r > m + 1)
					r--;
				else
					break;
			}
			else//sum<0���������ָ�������ƶ�һλ
			{
				if (l < m - 1)
					l++;
				else
					break;
			}

			if (l == m - 1 && r == m + 1)
				break;

			

		}
	}

	return res;
}


vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	vector<vector<int>> res;

	if (len < 3 || nums[0] > 0)
		return res;

	for (int i = 0; i < len-1; i++)
	{
		if (nums[i] > 0)
			break;

		int l = i + 1, r = len - 1;
		while (l<r)
		{
			long sum = nums[i] + nums[l] + nums[r];
			if (sum > 0)
			{
				while (l < r && nums[r] == nums[r - 1])
					r--;
				r--;
			}
				
			else if (sum < 0)
			{
				while (l < r && nums[l] == nums[l + 1])
					l++;
				l++;
			}
			else
			{
				res.push_back({ nums[i], nums[l], nums[r] });
				while (l < r && nums[l] == nums[l + 1])
					l++;
				while (l < r && nums[r] == nums[r - 1])
					r--;
				l++;
				r--;
			}
		}
		while (i < len - 1 && nums[i] == nums[i + 1])
			i++;
	}

	return res;
}


int main(void)
{
	//vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<int> nums = { 0,0,0,0,0,0 };
	vector<vector<int>> res;
	
	res = threeSum(nums);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

