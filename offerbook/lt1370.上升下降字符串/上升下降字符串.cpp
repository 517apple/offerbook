#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/increasing-decreasing-string/

*/



string sortString(string s) {
    int len = s.size();
    if (len < 2)
        return s;
    vector<int> vec(26, 0);

    for (auto ch : s)
        vec[ch - 'a']++;

    string res = "";
    while (res.size() != len)
    {
        for (int i = 0; i < 26; i++)
        {
            if (vec[i] > 0)
                res += (i + 'a');
            vec[i]--;
        }
        for (int i = 25; i >= 0; i--)
        {
            if (vec[i] > 0)
                res += (i + 'a');
            vec[i]--;
        }
    }
    return res;
}


int main(void)
{
    string s = "aaaabbbbcccc";
    sortString(s);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int maxSize = 0, len = grumpy.size();
        if (X == 0)
        {
            int TempMax = 0;
            for (int j = 0; j < len; j++)
            {
                if (grumpy[j] == 0)
                    TempMax += customers[j];
            }
            maxSize = max(maxSize, TempMax);
        }
        else
        {
            for (int i = 0; i <= len - X; i++)
            {
                //在[i,i+X)的区间内，不受grumpy的限制
                int TempMax = 0;
                for (int j = 0; j < len; j++)
                {
                    if ((j >= i && j < i + X) || grumpy[j] == 1)
                        TempMax += customers[j];
                }
                maxSize = max(maxSize, TempMax);
            }
        }

        return maxSize;
    }
};