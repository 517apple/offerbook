#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/insert-interval/

˼·��
1. ѭ������vector�е����䣬�ҵ���һ���Ҷ˵�ֵ����newInterval��˵�ֵ�ĵ�һ������
����Ľ��������漸�������
���н���
��û�н���

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
	while (i < len && intervals[i][1] < newInterval[0]) { // ��ǰ������������ߵģ����ص�������
		res.push_back(intervals[i]);
		i++;
	}
	//��˼ά̫ǿ��
	while (i < len && intervals[i][0] <= newInterval[1]) { // ��ǰ���������ص�������
		newInterval[0] = min(newInterval[0], intervals[i][0]); //���ȡ��С�ߣ����¸�����������
		newInterval[1] = max(newInterval[1], intervals[i][1]); //�Ҷ�ȡ�ϴ��ߣ����¸���������Ҷ�
		i++;
	}
	res.push_back(newInterval); // ѭ��������������Ϊ�ϲ�������䣬����res

	while (i < len) {                 // �����ұߣ�û�ص�������
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

