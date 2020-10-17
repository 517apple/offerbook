#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;


vector<int> sortedSquares(vector<int>& A) {
	int len = A.size();
	vector<int> ret(len);

	int i = 0, j = len - 1,index=len-1;
	while (j>i)
	{
		if (abs(A[i]) > abs(A[j]))
		{
			ret[index] = pow(A[i], 2);
			i++;
		}
		else
		{
			ret[index] = pow(A[j], 2);
			j--;
		}
		index++;
	}
	return ret;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

