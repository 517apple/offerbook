#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>



using namespace std;

/*
1. �ַ���Ϊ��ʱû���ǣ�˵����д�����ʱ��û�п��ǵ��쳣������coding��ʱ��һ��Ҫ���ⲿ�ֿ��Ǻ�
2. 


- ��`string s`ĩβ��char�ַ���

> s=s+'a';
> s+='a';  �ķ�ʽ�ǲ������;��s1û�г�ʼ���ռ�֮ǰ��s[1]='a'�Ĳ���Ҳ�ǲ�������ģ�


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

