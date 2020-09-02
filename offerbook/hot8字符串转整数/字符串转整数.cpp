#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;
/*
1. 首先判断第一个非空格字符是不是除了空格、-、数字之外的其它字符，如果是，则直接返回、
2. 忽略前面的空白字符，看第一个

难点：
1. 特殊情况+- -+的考虑
2. 边界条件的判断（INT_MAX/INT_MIN），我这里用了unsigned int 类型并且判断了两次
3. 由于字符串的最后一个字符是‘\0’，所以在这里不用考虑str的长度
*/
int myAtoi(string str) {
    int index = 0, res = 1;
    unsigned int num = 0;
    while (str[index] == ' ')
    {
        index++;
    }
    if (str[index] != '-' && str[index] != '+' && str[index] < '0' && str[index]>'9')
        return 0;

    if (str[index] == '-')
    {
        res = -1;
        index++;
    }
    else if (str[index] == '+')
    {
        res = 1;
        index++;
    }
    else;

    while (str[index] >= '0' && str[index] <= '9')
    {
        if (res == 1 && num > INT_MAX / 10)
            return INT_MAX;
        if (res == -1 && num > INT_MAX / 10)
            return INT_MIN;
        num *= 10;
        num += (unsigned int)(str[index] - '0');
        if (res == 1 && num > INT_MAX)
            return INT_MAX;
        if (res == -1 && num > INT_MAX)
            return INT_MIN;

        index++;
    }
    return num * res;
}

int main(void)
{
	string s = "01";
	cout << s[0] << endl;

	int num = 0, index = 0,res=1;
	int strlen = s.size();
	while (s[index]==' ')
	{
		index++;
	}
	if (s[index] != '-' && s[index] < '0' && s[index]>'9')
		return 0;
	if (s[index] == '-')
	{
		res = -1;
		index++;
	}
	while (s[index] >= '0' && s[index] <= '9')
	{
		if (num > INT_MAX / 10)
			return 0;
		num *= 10;
		num += (int)(s[index]-'0');
		index++;		
	}

	cout << num << endl;

    

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

