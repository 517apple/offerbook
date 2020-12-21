#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/score-after-flipping-matrix/

*/


int matrixScore(vector<vector<int>>& A) {
    int row = A.size();//行数
    // if(row==0)
    //     return 0;
    int column = A[0].size();//列数

    for (auto& vec : A)
    {
        if (vec[0] == 0)
        {
            for (int& x : vec)
            {
                if (x == 1)
                    x = 0;
                else
                    x = 1;
            }
        }
    }

    vector<int> count1(column, 0);
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (A[j][i] == 1)
                count1[i]++;
        }
    }

    int max = 0;
    for (int i = 0; i < column; i++)
    {
        if (count1[i] > row / 2)
        {
            max = max + count1[i] * pow(2, column - i - 1);
        }
        else
            max = max + (row - count1[i]) * pow(2, column - i - 1);

    }

    return max;


}


int main(void)
{
    vector<vector<int>> A = { {0, 0, 1, 1},{1, 0, 1, 0},{1, 1, 0, 0} };
    matrixScore(A);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

