#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;


/*
https://leetcode-cn.com/problems/zigzag-conversion/comments/

*/


string convert(string s, int numRows) {
    vector<string> temp(numRows);
    string res;
    if (s.empty() || numRows < 1) return res;
    if (numRows == 1) return s;
    for (int i = 0; i < s.size(); i++) {
        int ans = i / (numRows - 1);
        int cur = i % (numRows - 1);
        if (ans % 2 == 0) {  //���Ϊż����0
            temp[cur].push_back(s[i]); //���������򱣴�
        }
        if (ans % 2 != 0) {  //���Ϊ����
            temp[numRows - cur - 1].push_back(s[i]); //���������򱣴�
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        res += temp[i];
    }
    return res;
}


string convert1(string s, int numRows) {
    string res = "";
    if (numRows)
        return res;
    if (numRows == 1)
        return s;

    vector<string> temp(numRows);
    for (int i = 0; i < s.size(); i++)
    {
        int a = i / (numRows - 1);//�����Ľ������ȷ����ǰ�ַ��Ǵ����½�״̬��������״̬��
        int cur = i % (numRows - 1);//�����Ľ������ȷ����ǰ�ַ�Ӧ����ӵ��ĸ�����������

        if (a % 2 == 0)//����  �е��½�������
        {
            temp[cur].push_back(s[i]);
        }
        else
        {
            temp[numRows - cur - 1].push_back(s[i]);
        }
    }
    for (string s1 : temp)
        res += s1;

    return res;
}



int main(void)
{          
    string s = "LEETCODEISHIRING";

    convert(s, 4);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

