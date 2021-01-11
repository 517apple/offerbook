#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <unordered_map>

using namespace std;

/*
https://leetcode-cn.com/problems/first-unique-character-in-a-string/

������ɻ�����ڣ�unordered_map�᲻�����򣿣�
A:��������򣬲�һ���ǲ���˳��
*/


int firstUniqChar(string s) {
    int len = s.size();
    if (len == 0)
        return -1;
    unordered_map<char, int> mymap;
    for (char& ch : s)
    {
        mymap[ch]++;
    }
    int index = 0;
    for (auto& iter : mymap)
    {
        // if(iter.second==1)
        //     return index;
        cout << iter.first << ":" << iter.second << endl;
        index++;
    }
    return -1;
}


int main(void)
{
    string s = "loveleetcode";

    firstUniqChar(s);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

