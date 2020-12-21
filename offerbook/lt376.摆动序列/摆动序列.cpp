#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/wiggle-subsequence/

*/


int wiggleMaxLength(vector<int>& nums) {
    int maxlen = 2;
    int len = nums.size();
    if (len <= 2)
        return len;

    int index = 1;
    while (index < len && nums[index - 1] == nums[index])
        index++;
    if (index == len)//序列全部相同的时候输出 1 ？
        return 1;

    bool diff = ((nums[index] - nums[index - 1]) > 0 ? true : false);//首差值为正，diff则为true,否则为false

    int lentemp = 2;
    for (int i = index + 1; i < len; i++)
    {
        bool temp = ((nums[i] - nums[i - 1]) > 0 ? true : false);

        if (diff != temp)
        {
            lentemp++;
            maxlen = max(maxlen, lentemp);
        }
        else
            lentemp = 2;
        diff = temp;
    }
    return maxlen;
}

int main(void)
{
    vector<int> arr = { 1, 7, 4, 9, 2, 5 };
    wiggleMaxLength(arr);

    cout << "hello world" << endl;
    system("pause");
    return 0;

}

