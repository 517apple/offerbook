#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/insert-interval/

思路：
1. 循环遍历vector中的区间，找到第一个右端点值大于newInterval左端点值的第一个区间
区间的交集有下面几种情况：
①有交集
②没有交集

*/


vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> res;

	if (intervals.empty() && !newInterval.empty())
	{
		res.push_back(newInterval);
		return res;
	}

	if (intervals.empty() && !newInterval.empty())
		return res;

	

	int i = 0,len=intervals.size();
	while (i < len && intervals[i][1] < newInterval[0]) { // 当前遍历的是蓝左边的，不重叠的区间
		res.push_back(intervals[i]);
		i++;
	}
	//这思维太强了
	while (i < len && intervals[i][0] <= newInterval[1]) { // 当前遍历是有重叠的区间
		newInterval[0] = min(newInterval[0], intervals[i][0]); //左端取较小者，更新给兰区间的左端
		newInterval[1] = max(newInterval[1], intervals[i][1]); //右端取较大者，更新给兰区间的右端
		i++;
	}
	res.push_back(newInterval); // 循环结束后，兰区间为合并后的区间，推入res

	while (i < len) {                 // 在蓝右边，没重叠的区间
		res.push_back(intervals[i]);
		i++;
	}
	return res;

}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

