#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
https://leetcode-cn.com/problems/smallest-string-with-swaps/

*/


//����������� [0,3] [1,2] [0,2] s="bcad"
class DSU {
	vector<int> parent;

public:
	DSU(int n) {
		for (int i = 0; i < n; i++)
			parent.push_back(i); //0 1 2 3
	}

	//[0 3]  p[0]=3
	//[1 2]    
	//[0 2]
	void merge(int x, int y) {
		int rootx = find(x);//0 3
		int rooty = find(y);//3 
		if (rootx != rooty) {
			parent[rootx] = rooty;
		}
	}

	int find(int x) {
		if (x != parent[x])
			parent[x] = find(parent[x]);

		return parent[x];
		//return x == parent[x] ? x : find(parent[x]);
	}
};

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
	int len = s.size();
	if (len < 2 || pairs.size() == 0)
		return s;

	//��һ���������⽻���Ľ������벢�鼯
	DSU dsu(len);//�������鼯
	for (vector<int>& p : pairs)
	{
		dsu.merge(p[0], p[1]);
	}

	//�ڶ���������ӳ���ϵ
	//��һ����Ҫset�ɣ�vectorӦ��Ҳ�ǿ��Ե�
	unordered_map<int, set<int>> mymap;
	for (int i = 0; i < len; i++)
		mymap[dsu.find(i)].insert(i);

	for (auto& e : mymap)
	{
		string str;
		//��ȡ������ÿ��λ�õ��ַ�
		for (auto& i : e.second)
			str += s[i];
		//����
		sort(str.begin(), str.end());
		int cnt = 0;
		for (auto& i : e.second)
			s[i] = str[cnt++];
	}

	return s;

}

int main(void)
{
    string s = "dcab";
    vector<vector<int>> pairs = { {0,3},{1,2},{0,2} };

    smallestStringWithSwaps(s, pairs);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

