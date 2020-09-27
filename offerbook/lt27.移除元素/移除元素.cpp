#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
https://leetcode-cn.com/problems/remove-element/


*/

int removeElement(vector<int>& nums, int val) {
    int length = nums.size();
    int i = 0, j = 0;

    for (i = 0; i < length; i++)
    {
        if (nums[i] != val)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
    return j;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

