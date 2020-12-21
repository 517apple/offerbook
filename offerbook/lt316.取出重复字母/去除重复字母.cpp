#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <unordered_map>
#include <map>

using namespace std;

/*
https://leetcode-cn.com/problems/remove-duplicate-letters/


*/


/*
参考了题解
1.遍历新字符
2. 如果遇到的新字符比已经存储的最后一个字符串要小，那就需要考虑该字符后边是否还有这个字符

太精妙了！！

*/
string removeDuplicateLetters(string s) {
    vector<int> hashtable(128, 0);//以后需要注意审题，题目属于小范围的题目的话，是可以用vector来代替hashmap的功能的
    vector<bool> visited(128, false);
    for (char& ch : s)
        hashtable[ch]++;

    string result = "0";//预先放置一个0，避免了后面判空

    for (char& ch : s)
    {
        hashtable[ch]--;
        if (visited[ch])
            continue;

        while (ch < result.back() && hashtable[result.back()])
        {
            visited[result.back()] = false;
            result.pop_back();
        }
        result += ch;
        visited[ch] = true;
    }
    return result.substr(1);
}



/*
思路：
1. 使用map将数组存在的每个相对位置都存储起来
2. 遍历map，取出相对索引并更新
思路不对！！
*/
string My_removeDuplicateLetters(string s) {
    int len = s.size();
    string ans;
    if (len < 2)
        return s;
    unordered_map<char, vector<int>> mymap;
    for (int i = 0; i < len; i++)
    {
        mymap[s[i]].push_back(i);
    }
    int index = -1;
    for (auto iter : mymap)
    {
        cout << iter.first << ":";
        for (auto x:iter.second)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return ans;
}


int main(void)
{
    string s = "cbacdcbc";
    cout << s << endl;

    My_removeDuplicateLetters(s);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

