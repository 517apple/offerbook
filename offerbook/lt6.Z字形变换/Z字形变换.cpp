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
        if (ans % 2 == 0) {  //结果为偶数或0
            temp[cur].push_back(s[i]); //按余数正序保存
        }
        if (ans % 2 != 0) {  //结果为奇数
            temp[numRows - cur - 1].push_back(s[i]); //按余数倒序保存
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
        int a = i / (numRows - 1);//除数的结果用于确定当前字符是处于下降状态还是上升状态，
        int cur = i % (numRows - 1);//余数的结果用于确定当前字符应该添加到哪个容器序列中

        if (a % 2 == 0)//处于  中的下降序列中
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

