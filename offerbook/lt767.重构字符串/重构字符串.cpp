#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/reorganize-string/
*/


string reorganizeString(string S) {
    int len = S.size();
    if (len < 2)
        return S;
    vector<int> arr(26, 0);
    string ans = "";
    for (auto ch : S)
        arr[ch - 'a']++;

    while (ans.size() <= len)
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] > 0)
            {
                if (ans == "")
                {
                    ans += (i + 'a');
                }
                else
                {
                    if (ans.back() != (i + 'a'))
                        ans += (i + 'a');
                    else
                        return "";
                }
                arr[i]--;
            }
        }
        //cout << ans << endl;
    }

    return ans;

}



int main(void)
{
    string S = "aab";

    reorganizeString(S);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

