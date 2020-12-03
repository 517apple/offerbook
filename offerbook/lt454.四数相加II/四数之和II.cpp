#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <map>

using namespace std;


/*
https://leetcode-cn.com/problems/4sum-ii/

*/


int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int res = 0;
    map<int, int> mymapAB;

    for (auto x : A)
        for (auto y : B)
            mymapAB[x + y]++;


    for (auto x : C)
        for (auto y : D)
            res += mymapAB[-(x + y)];

    return res;
}


int main(void)
{
    vector<int> A = { 1,2 };
    vector<int> B = { -2,-1 };
    vector<int> C = { -1,2 };
    vector<int> D = { 0,2 };

    fourSumCount(A, B, C, D);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

