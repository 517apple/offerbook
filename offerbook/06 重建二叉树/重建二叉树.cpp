#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

//��������㶨��
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*
Q:��֪ǰ���������������У��ؽ����ö�����
A:
1. ����ǰ������ĵ�һ���ڵ�Ϊroot�ڵ㣬��������������зֱ������������������Ԫ��
2. ѭ���ݹ飬�Ӷ�ȷ�����Ľṹ

2020-7-4 22:01:04
�˴�������δ��ɣ�������ս
*/

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return NULL;
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if(startPreorder==endPreorder)
	{
		
	}

	return NULL;
}


int main(void)
{
	//*s  �ȼ���  s[0]
	const char* s = "Luo";
	for (size_t i = 0; i < strlen(s); i++)
	{
		printf("%c ", s[i]);
	}
//	throw exception("test!");
	cout << "hello world" << endl;
	system("pause");
	return 0;

}

