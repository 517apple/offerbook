#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;


/*
链接：https://leetcode-cn.com/problems/intersection-lcci/

*/
vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
	vector<float> res;
	float k1 = (end1[1] - start1[1]) / (end1[0] - start1[0]) * 1.0;
	float k2 = (end2[1] - start2[1]) / (end2[0] - start2[0]) * 1.0;
	float X1min = (start1[0] > end1[0] ? end1[0] : start1[0]) * 1.0;
	float X1max = (start1[0] > end1[0] ? end1[0] : start1[0]) * 1.0;
	float X2min = (start2[0] > end2[0] ? end2[0] : start2[0]) * 1.0;
	float X2max = (start2[0] > end2[0] ? end2[0] : start2[0]) * 1.0;
	float x1=X1min, x2=X2min;
	float y1 = k1 * x1;  //有误
	float y2 = k2 * x2;

	//没有交点的情况：1.横坐标没有


}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

