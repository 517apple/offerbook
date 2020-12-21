#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
https://leetcode-cn.com/problems/group-anagrams/

*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ans;
	
	map<string, vector<string>> M;
	for (int i=0;i<strs.size();i++)
	{
		string s = strs[i];
		sort(s.begin(), s.end());
		M[s].push_back(strs[i]);
	}

	for (auto iter = M.begin(); iter != M.end(); iter++)
		ans.push_back(iter->second);

	return ans;

}

vector<vector<string>> MygroupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;

    if (strs.size() == 0)
    {
        return ans;
    }

    vector<vector<int>> strvec;
    for (string& s1 : strs)
    {
        vector<int> temp;
        if (s1.size() == 0)
        {
            strvec.push_back({ -1 });
            continue;
        }
        for (auto ch : s1)
            temp.push_back(ch - 'a');
        sort(temp.begin(), temp.end());
        strvec.push_back(temp);
    }
    for (int i = 0; i < strvec.size(); i++)
    {
        vector<int> temp = strvec[i];
        if (temp.size() == 0)
            continue;
        vector<string> str;
        str.push_back(strs[i]);
        for (int j = i + 1; j < strvec.size(); j++)
        {
            if (temp == strvec[j])
            {
                str.push_back(strs[j]);
                strvec[j].clear();
            }

        }
        ans.push_back(str);
    }
    return ans;
}

int main(void)
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	groupAnagrams(strs);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

