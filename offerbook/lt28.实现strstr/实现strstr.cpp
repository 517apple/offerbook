#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
https://leetcode-cn.com/problems/implement-strstr/

˼·��
1. �Ƚ������ַ����Ĵ�С�����needle�ĳ��ȴ���haystack�ĳ��ȣ���ֱ�ӷ���-1
2. forѭ�����ҵ�needle

���Լ��Ľⷨ��˼·���ǲ���׼ȷ�ģ�������Ҫ���ǵ��������Ҳ�Ƚ϶�
������ȷ�Ľⷨ�Ƚϼ�࣬����forѭ���͸㶨��
*/

//����break���÷�Ҫ����
int strStr(string haystack, string needle) {
	int len1 = haystack.size(), len2 = needle.size();

	if (len2 == 0)
		return 0;
	int i = 0, j = 0;
	for ( i = 0; i < len1-len2+1; i++)
	{
		for ( j = 0; j < len2; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (j == len2)
			return i;
	}
	return -1;

}


int strStr1(string haystack, string needle) {
	int len1 = haystack.size(),len2=needle.size();

	if (len2 == 0)
		return 0;
	if (len2 > len1)
		return -1;

	int position = -1,index=0;
	char ch = needle[0];


	for (int i = 0; i < len1; i++)
	{
		if (ch == haystack[i])
		{
			if (needle[0] == haystack[i])
				position = i;
			if (index < len2)
			{
				index++;
				if (index == len2)
					return position;
				ch = needle[index];
			}
		}
		else
		{
			index = 0;
			continue;
		}
	}
	return -1;

}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

