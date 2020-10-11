#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>
#include <unordered_map>

using namespace std;

/*
https://leetcode-cn.com/problems/valid-parentheses/

˼·��
1. ��������flag���������ŵĴ��������ۼӣ������ŵĴ��������ۼ�
2. ����������ʱ���flag����ֵ�Ƿ�Ϊ0
3. ���ֿո�ʱ����
4. Ҫ�ԣ�������ļ����жϣ�ȷ�������flag�Ѿ�����

����˼·û�취�ж�����()�Ƿ�����ȷ��

*/


bool isValid(string s) {
	int f1, f2, f3,f4,f5;//�ֱ��ʾ(),{},[],�Լ����������{},[]
	f1 = f2 = f3 =f4=f5= 0;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		switch (c)
		{
			case '(':
				f1++;
					break;
			case '{':
				if (f1 != 0)
					f4++;
				else 
					f2++;
					break;
			case '[':
				if (f1 != 0)
					f5++;
				else
					f3++;
					break;
			case ')':
				if (f1 == 0|| f4!=0 || f5!=0)
					return false;
				else
				{
					f1--;
				}
				break;
			case '}':
				if (f2 == 0)
					return false;
				else
				{
					if (f1 != 0 && f4!=0)
						f4--;
					else
						f2--;
				}
				break;
			case ']':
				if (f3 == 0)
					return false;
				else
				{
					if (f1 != 0 && f5 != 0)
						f5--;
					else
						f3--;
				}
				break;

			default:
				break;
		}
	}
	if (f1 + f2 + f3 == 0)
		return true;
	else
		return false;

}

/*
* 
�����Ŀ������ȷʵ���ʺ�stack�����ԡ�
��ֱ�������ϣ�

*/


bool isValid(string s)
{
	if (s.size() % 2 == 1)
		return false;
	unordered_map<char, int> m{ {'(',1}, {'{',2}, {'[',3}, {')',4}, {'}',5}, {']',6} };
	stack<char> st;
	for (char c : s)
	{
		if (m[c] >= 1 && m[c] <= 3)
			st.push(c);
		else if (!st.empty() && m[st.top()] == m[c] - 3)
			st.pop();
		else
			return false;
	}
	if (!st.empty())
		return false;
	return true;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

