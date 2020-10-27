#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <cassert>

/*
https://leetcode-cn.com/problems/partition-labels/


*/


using namespace std;

vector<int> partitionLabels(string S) {
	vector<int> result;
	unordered_map<char, int> map;
	int start = 0, end = 0;
	for (int i = 0; i < S.size(); i++)
	{
		map[S[i]] = i;
	}
	for (int i = 0; i < S.size(); i++)
	{
		end = max(end, map[S[i]]);
		if (i == end)
		{
			result.push_back(end - start + 1);
			start = i + 1;
		}
	}

	return result;

}


int main(void)
{
//	cout << argc << endl;
	cout << __argv[0] << endl;
	cout << __LINE__ << endl;

	assert(1);
	partitionLabels("ababcbacadefegdehijhklij");

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

