#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>


using namespace std;

/*


https://leetcode-cn.com/problems/intersection-of-two-arrays/



*/


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (!nums1.size() || !nums2.size())
        return res;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());


    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            if (nums1[i] != res.back())
                res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
            j++;
        else
            i++;
    }
    return res;
}




int main(void)
{
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };

    vector<int> res = intersection(nums1, nums2);



	cout << "hello world" << endl;
	system("pause");
	return 0;

}

