#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>



using namespace std;

/*
1. 字符串为空时没考虑，说明在写程序的时候没有考虑到异常处理，在coding的时候一定要把这部分考虑好
2. 


- 在`string s`末尾加char字符：

> s=s+'a';
> s+='a';  的方式是不允许的;在s1没有初始化空间之前，s[1]='a'的操作也是不被允许的；


*/


string longestCommonPrefix(vector<string>& strs) {
    string s1 = "";
    cout << s1 << endl;
    int len = strs.size();
    if (len == 0)
        return s1;
    for (int i = 0; i < strs[0].size(); i++)
    {
        int j = 0;
        while ((j < len) && (i < strs[0].size()) && (i < strs[j].size()) && (strs[0][i] == strs[j][i]))
            j++;
        if (j == len)
            s1 = s1 + strs[0][i];
        else
            break;
    }
    return s1;
}

int main(void)
{
	vector<string> strs = { "flower", "flow", "flight" };

	string s1 = longestCommonPrefix(strs);

	cout << s1 << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

