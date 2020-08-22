#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

int lengthOfLongestSubstring(string s) {

	return 0;
}

int main(void)
{
	string s1("abcabcbb");

	int maxLen = 1,strlen=s1.length();
	string::iterator pStart = s1.begin();

	for (size_t i = 0; i < strlen; i++)
	{
		for (size_t j = i+1; j < strlen; j++)
		{
			string::iterator p = find(pStart +i+1, pStart +j, s1[i]);

			if(p!=pStart+j)
				break;
			else
			{
				maxLen = maxLen > (p - pStart - i) ? maxLen : (p - pStart - i);
			}

		}
	}

	cout << maxLen << endl;

	string::iterator p = find(s1.begin(), s1.end(), 'f');
	if (p != s1.end())
		cout << p - s1.begin() << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

