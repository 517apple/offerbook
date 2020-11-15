#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
https://leetcode-cn.com/problems/k-closest-points-to-origin/

解法：
最直接的解法：
1. 先算出各个点到原点的距离平方，然后进行排序，取出前K个数即可
*/

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	unordered_map<double, vector<vector<int>>> m;
	for (auto& i : points) {
		m[sqrt(i[0] * i[0] + i[1] * i[1])].emplace_back(i);
		//m.insert(make_pair(sqrt(i[0] * i[0] + i[1] * i[1]), i));
	}
	m[1].emplace_back(vector<int>{1, 2});
	m[1].emplace_back(vector<int>{1, 2});

	vector<int> test;
	test.emplace_back(vector<int>{1, 2});
	int cnt = 0;
	vector<vector<int>> res;
	for (auto& nums : m) {
		for (auto& iter2 : nums.second) {
			if (cnt++ < K) {
				res.emplace_back(iter2);
			}
			else {
				break;
			}
		}
		if (cnt == K) break;
	}
	return res;
}



int main(void)
{
	vector<vector<int>> nums = { {1, 3},{1, 3} };

	kClosest(nums, 2);


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

