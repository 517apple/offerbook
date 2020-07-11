#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
题目：输入一个整数数组，判断该数组是不是某二搜索树的后续遍历的结果
直接参照剑指offer，这种递归的思路要着重学习一下
*/

bool VerifySeqofBST(int a[], int length)
{
	if (a == NULL || length <= 0)
		return false;
	int root = a[length - 1];

	//根据二叉搜索树的性质，判断区分出左右子树的序列
	int i = 0;
	for (; i < length - 1; i++)
	{
		if (root > a[i])
			break;
	}
	int j = i;
	for (; j < length - 1; j++)
	{
		if (root > a[j])
			return false;
	}

	//对区分出的左右子树进行递归判断
	bool left = true;
	VerifySeqofBST(a, i);

	bool right = true;
	VerifySeqofBST(a+i, j-i);

	return (left && right);
}

int main(void)
{

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

