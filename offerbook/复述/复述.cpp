#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>


using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int len = nums.size();
    vector<int> temp = nums, res(len, 0);
    sort(temp.begin(), temp.end());
    for (auto x : temp)
        cout << x << " ";
    for (int i = 0; i < len; i++)
    {
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            cout << left << ":" << right << ":" << mid << endl;
            if (temp[mid] == nums[i])
            {
                while (mid >= 0 && temp[mid] == nums[i])
                    mid--;
                res[i] = mid;
                break;
            }
            else if (temp[mid] > nums[i])
            {
                right = mid-1;
            }
            else
                left = mid+1;
        }
    }
    return res;
}

int main(void)
{
    vector<int> nums = {8, 1, 2, 2, 3};
    nums = smallerNumbersThanCurrent(nums);
    for (auto x : nums)
        cout << x << " ";


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

