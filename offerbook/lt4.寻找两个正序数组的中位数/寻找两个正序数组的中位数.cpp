#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/


*/



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr;
    int i, j,len1,len2;
    i = j = 0;
    len1 = nums1.size();
    len2 = nums2.size();
    while (i < len1 && j < len2)
    {
        if (nums1[i] < nums2[j])
        {
            arr.push_back(nums1[i]);
            i++;
        }
        else
        {
            arr.push_back(nums2[j]);
            j++;
        }
            
    }
    if (i == len1)
        while (j < len2)
            arr.push_back(nums2[j++]);

    if (j == len2)
        while (i < len1)
            arr.push_back(nums1[i++]);
        
    int len = arr.size();
    if (len % 2 == 1)
        return arr[(len - 1) / 2]*1.0;
    else
        return (arr[(len - 1) / 2]+arr[len/2]+0.0)/2;

}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

