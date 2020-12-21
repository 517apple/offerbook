#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <unordered_map>


using namespace std;

/*
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

�ݹ���ݵ�˼·һֱ��̫�������������Ŀ�պÿ���������






*/

void dfs(vector<string>& res, string str, string& digits, unordered_map<char, string>& mymap, int k)
{
	if (k == digits.size())
	{
		res.push_back(str);
		return;
	}
	string tmp = mymap[digits[k]];
	for (char ch : tmp)
	{
		str.push_back(ch);
		dfs(res, str, digits, mymap, k + 1);
		str.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	int len = digits.size();
	if (len == 0)
		return res;
	//����������������ĸ֮��Ķ�Ӧ��ϵ�Ľṹ����ʹ��map�����б�ʶ
	unordered_map<char, string> mymap{ {'0',""}, {'1',""}, {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"} };

	dfs(res, "", digits, mymap, 0);

	for (auto s : res)
		cout << s << endl;

	return res;
}



int main(void)
{
	letterCombinations("23");

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

