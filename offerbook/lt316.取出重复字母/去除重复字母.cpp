#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <unordered_map>
#include <map>

using namespace std;

/*
https://leetcode-cn.com/problems/remove-duplicate-letters/


*/


/*
�ο������
1.�������ַ�
2. ������������ַ����Ѿ��洢�����һ���ַ���ҪС���Ǿ���Ҫ���Ǹ��ַ�����Ƿ�������ַ�

̫�����ˣ���

*/
string removeDuplicateLetters(string s) {
    vector<int> hashtable(128, 0);//�Ժ���Ҫע�����⣬��Ŀ����С��Χ����Ŀ�Ļ����ǿ�����vector������hashmap�Ĺ��ܵ�
    vector<bool> visited(128, false);
    for (char& ch : s)
        hashtable[ch]++;

    string result = "0";//Ԥ�ȷ���һ��0�������˺����п�

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
˼·��
1. ʹ��map��������ڵ�ÿ�����λ�ö��洢����
2. ����map��ȡ���������������
˼·���ԣ���
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

