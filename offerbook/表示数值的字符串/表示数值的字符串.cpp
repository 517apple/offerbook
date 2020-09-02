#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;
/*
这题要考虑的特殊情况比较多，所以最终的结果没有调试正确
*/
bool firstis(char c)
{
	if (c == '+' || c == '-' || (c >= '0' && c <= '9') || c == ' ')
		return true;
	else
		return false;
}

bool otheris(char c)
{
	if (c == 'E' || c == 'e' || c == '.' || (c >= '0' && c <= '9') || c == ' ')
		return true;
	else
		return false;
}

bool isNumber(string s) {
	int index = 0, strlen = s.length();
	cout << strlen << endl;
//	cout << firstis(s[0]) << endl;
	if (!firstis(s[0]))
		return false;

	index++;
	int numofpoint = 0, numofE = 0;
	while (index < strlen)
	{
		if (!otheris(s[index]))
			return false;

		if ((s[index] == 'E' || s[index] == 'e'))
		{
			numofE++;
			if (index == strlen - 1)
				return false;
		}
		if (s[index] == '.')
			numofpoint++;

		if (numofE >= 2 || numofpoint >= 2)
			return false;

		index++;
	}
	return true;
}

int main(void)
{
	string s = "1 ";

	cout << isNumber(s) << endl;


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

