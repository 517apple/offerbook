#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;
/*
1. �����жϵ�һ���ǿո��ַ��ǲ��ǳ��˿ո�-������֮��������ַ�������ǣ���ֱ�ӷ��ء�
2. ����ǰ��Ŀհ��ַ�������һ��

�ѵ㣺
1. �������+- -+�Ŀ���
2. �߽��������жϣ�INT_MAX/INT_MIN��������������unsigned int ���Ͳ����ж�������
3. �����ַ��������һ���ַ��ǡ�\0�������������ﲻ�ÿ���str�ĳ���
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

