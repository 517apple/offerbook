#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <unordered_map>

using namespace std;

/*
https://leetcode-cn.com/problems/word-pattern/

*/


bool wordPattern(string pattern, string s) {
    if (s.size() == 0)
        return false;

    vector<string> arr;
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            tmp.push_back(s[i]);
        }
        else
        {
            arr.push_back(tmp);
            tmp.clear();
        }
        if (i == (s.size() - 1))
        {
            arr.push_back(tmp);
            tmp.clear();
        }
    }
    unordered_map<char, string> mymap;//只用一个map不够，还需要添加一个string 与 char之间的映射
    int index = 0;
    for (char ch : pattern)
    {
        if (mymap.find(ch) != mymap.end())
        {
            if (mymap[ch] != arr[index])
                return false;
        }
        else {
            mymap[ch] = arr[index];
        }
        index++;
    }

    return true;
}


int main(void)
{
    string  pattern = "abba", str = "dog dog dog dog";

    wordPattern(pattern, str);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

