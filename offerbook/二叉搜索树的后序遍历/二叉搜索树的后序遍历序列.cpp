#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ��������Ľ��
ֱ�Ӳ��ս�ָoffer�����ֵݹ��˼·Ҫ����ѧϰһ��
*/

bool VerifySeqofBST(int a[], int length)
{
	if (a == NULL || length <= 0)
		return false;
	int root = a[length - 1];

	//���ݶ��������������ʣ��ж����ֳ���������������
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

	//�����ֳ��������������еݹ��ж�
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

