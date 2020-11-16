#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
https://leetcode-cn.com/problems/queue-reconstruction-by-height/comments/

*/

bool cmp(vector<int> v1, vector<int> v2)
{
	if (v1[0] < v2[0])
		return true;
	else if (v1[0] == v2[0])
	{
		if (v1[1] > v2[1])
			return true;
		else
			return false;
	}
	
	return false;
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	int count = people.size();
	vector<vector<int>> res(count);
	sort(people.begin(), people.end(), cmp);
	set<int> s;
	for (int i = 0; i < count; ++i)
	{
		s.insert(i);
	}
	for (int i = 0; i < count; i++)
	{
		auto iter = s.begin();
		int x = people[i][1];
		while (x--)
			iter++;
		res[*iter] = people[i];
		s.erase(iter);
	}

	return res;
}

int main(void)
{
	vector<vector<int>> people = { {7, 0} ,{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	
	set<int> s;
	for (int i = 1; i <= 10; ++i)
	{
		s.insert(i);
	}
	auto iter = s.begin();
	cout << *iter + 3 << endl;
	//cout<<s[1]<<endl;


	reconstructQueue(people);
	

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

