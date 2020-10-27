#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/

特殊点：
1. 正负号
2. 大数
*/
int strToInt(string str) {
    int ans = 0, len = str.size();
    int sign = 1;
    int i = 0;
    while (isblank(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    for (; i < len; i++)
    {
        char ch = str[i];
        if (isdigit(ch))
        {
            int x = (int)(ch - '0');
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && x > 7))            
                return (sign > 0 ? INT_MAX : INT_MIN);
            ans = ans * 10 + x;

            continue;
        }
        break;
    }

    return ans * sign;
}


int main(void)
{
	string s("  123n");
	cout << strToInt(s) << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

