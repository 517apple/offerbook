#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/remove-k-digits/


*/


    string removeKdigits(string num, int k) {
        int len = num.size();
        if (len == k)
            return "0";

        stack<int> s;
        for (int i = 0; i < len; i++)
        {
            int x = num[i] - '0';
            if (s.empty())
            {
                s.push(x);
                continue;
            }
            if (k > 0 && x < s.top())
            {
                while (!s.empty() && k > 0 && x < s.top())
                {
                    s.pop();
                    k--;
                }
                s.push(x);
                continue;
            }
            s.push(x);
        }
        while (k--)
            s.pop();

        string ans = "";
        int index = s.size() - 1;
        vector<char> stk(s.size(), '0');
        while (!s.empty())
        {
            stk[index] = s.top() + '0';
            index--;
            s.pop();
        }
        bool isLeadingZero = true;
        for (auto& digit : stk) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;

    }


int main(void)
{
	string num = "112";
	int k = 1;

	//removeKdigits(num, k);

	string s1 = "";
	char ch = 'a';
	s1 += ch;
	string s2 = "qwer";

	s1 += s2;



	cout << "hello world" << endl;
	system("pause");
	return 0;

}

