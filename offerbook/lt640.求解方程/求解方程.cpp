#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <sstream>

using namespace std;

/*
https://leetcode-cn.com/problems/solve-the-equation/
我的思路是：
1. 先假设输入是合法的
2. 用两个栈分别存储数值和x的系数，并在等号的右边堆参数取反

!! 没有考虑一个数字以上的这种情况  22+33
*/

bool isnum(char c)
{
	return (c >= '0' && c<='9');
}

string solveEquation(string equation) {
	string res = "";
	int len = equation.length(); 

	vector<int> s, sx;
	int boo = 1,boorl=1,s1=0,sx1=0;
	
	bool flagstart = false;

	char b,c;
	

	for (size_t i = 0; i < len; i++)
	{	
		c= equation[i];
		
		if (i == 0 || c == '=')
			flagstart = true;

		if (c == 'x')
		{
			if (flagstart == true)
			{
				if (isnum(b))
					sx.push_back((b - '0') * boo * boorl);
				else
					sx.push_back(1 * boo * boorl);
				flagstart = false;
			}
			else
			{
				if (isnum(b))
					sx.push_back((b - '0') * boo * boorl);
				else
					sx.push_back(1 * boo * boorl);
			}
		}
		else if (c == '+')
		{
			boo = 1;
		}
		else if (c == '-')
		{
			boo = -1;
		}
		else if (isnum(c))
		{
			if (i == len - 1 || (i != len - 1 && equation[i + 1] != 'x'))
			{
				s.push_back((c - '0') * boo * boorl);
			}
				
		}
		else if (c == '=')
		{
			boorl = -1;
			boo = 1;
		}
		else;

		b = c;
	}

	if (s.size() == 0)
		s.push_back(0);
	for (auto a1 : s)
	{
		cout << a1 << " ";
		s1 += a1;
	}
	cout << endl;
	

	for (auto a1 : sx)
	{
		cout << a1 << " ";
		sx1 += a1;
	}
	cout << endl;
	

	if (sx1 == 0 && s1 == 0)
		res = "Infinite solutions";
	else if (sx1 == 0 && s1 != 0)
		res = "No solution";
	else
	{
		stringstream ss;
		ss << s1 / sx1 * (-1);
		res = "x=" + ss.str();
	}

	return res;
}


int main(void)
{
	string s1 = "x+5-3+x=6+x-2";
	s1 = "2x+3x-6x=x+2";
	//s1 = "2x=x";
	string ans = solveEquation(s1);

	cout << ans << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

