#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode-cn.com/problems/container-with-most-water/
*/


/*
1. 自己的解法
*/
int maxArea1(vector<int>& height) {
    int len = height.size();
    int max = 0, temp = 0;
    int maxLeft = 0;
    for (int left = 0; left < len; left++)
    {
        if (height[left] > maxLeft)
        {
            maxLeft = height[left];
            int maxRight = 0;

            for (int right = len - 1; right > left; right--)
            {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    continue;


                temp = (right - left) * (height[right] < height[left] ? height[right] : height[left]);

                if (max < temp)
                    max = temp;
            }
        }
        else
            continue;
    }
    return max;
}

/*
1. 左右指针同时移动
*/
int maxArea(vector<int>& height) {
    int res = 0, left = 0, right = height.size() - 1;
    while (left<right)
    {
        int temp = (right - left) * min(height[left], height[right]);
        res = max(res, temp);
        height[left] < height[right] ? left++ : right--;
    }
    return res;
}


int main(void)
{
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };
	cout << maxArea(nums) << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

