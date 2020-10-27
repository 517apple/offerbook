#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

string longestPalindrome(string s) {
	int len = s.size();
	if (len < 2)
		return s;
	int maxlen = 1,x=0,y=0;
	string ans = "";
	ans.push_back(s[0]);
	for (int i = 0; i < len; i++)
	{
		int j = i, k = len - 1;
		for (; k > i; k--)
		{
			j = i;
			int m = k;
			while (s[j] == s[m])
			{
				if (j == m)
				{
					maxlen = max(maxlen, 2 * (j - i) + 1);
					if (maxlen > ans.size())
						ans = s.substr(i, maxlen);
				}
					
				if (j > m)
				{
					maxlen = max(maxlen, 2 * (j - i));
					if (maxlen > ans.size())
						ans = s.substr(i, maxlen);
				}
					
				if (j < m)
				{
					j++;
					m--;
				}
				else
				{
					break;
				}
			}
		}
	}
	return ans;

}

int main(void)
{
	string s1 = "cbbd";
	string s2 = longestPalindrome(s1);

	cout << s2 << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

