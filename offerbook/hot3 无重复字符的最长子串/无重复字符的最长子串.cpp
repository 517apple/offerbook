#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <unordered_map>

using namespace std;


/*
直接使用两个指针的做法还不能处理;pwwkew 这种字符串类型
*/
int lengthOfLongestSubstring1(string s) {
	unordered_map<char, int> m1;
	int maxLen = 1, strlen = s.length();
	if (strlen <= 1)
		return strlen;
	int pleft = 0, pright = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (m1[s[i]] == false)
		{
			m1[s[i]] = true;
			pright++;
		}
		else
		{
			if (m1[s[i]] == m1[s[i - 1]])
				pleft = pright;
			pright++;
			pleft++;
		}
	}

	maxLen = pright - pleft;

	return maxLen;
}


int lengthOfLongestSubstring(string s) {
	int len = s.size();
	if (len <= 1)
		return len;
	vector<int> mymap(130, 0);
	int i = 0, j = 0,maxlen=0;

	for (; j < len; j++)
	{
		mymap[s[j]]++;
		while (mymap[s[j]] > 1)
			mymap[s[i++]]--;
		if (j - i + 1 > maxlen)
			maxlen = j - i + 1;
	}
	return maxlen;

}

int main(void)
{
	string s1("pwwkew");

	int len = lengthOfLongestSubstring(s1);
	
	cout << len << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

