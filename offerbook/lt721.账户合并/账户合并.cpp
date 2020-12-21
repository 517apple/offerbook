#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;


/*
https://leetcode-cn.com/problems/accounts-merge/


*/


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<string>> mymap;
    vector<vector<string>> ans;
    for (vector<string>& item : accounts)
    {
        string name = item[0];
        vector<string> mails = mymap[name];
        for (int i = 1; i < item.size(); i++)
        {
            int index = 0;
            for (; index < mails.size(); index++)//ШЅжи
            {
                if (item[i] == mails[index])
                    break;
            }
            if (index == mails.size())
                mymap[name].push_back(item[i]);
        }
    }
    for (auto& item : mymap)
    {
        vector<string> tmp;
        tmp.push_back(item.first);
        for (auto& s1 : item.second)
            tmp.push_back(s1);
        ans.push_back(tmp);
    }
    return ans;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

