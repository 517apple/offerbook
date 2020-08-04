#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 


/*
��������һЩ���������
1. ����
2. ������ǰ�к��������

�ο�����1��https://blog.csdn.net/qq_40693171/article/details/99745321
*/
using namespace std;

struct BinaryTreeNode
{
	int m_nValue = 0;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
};

//�����㷨
BinaryTreeNode* createBiTree() {
	BinaryTreeNode* root;
	int ch;
	cin >> ch;
	if (ch == 0)
		root = NULL;
	else {
		root = new BinaryTreeNode;
		root->m_nValue = (int)ch;
		root->m_pLeft = createBiTree();
		root->m_pRight = createBiTree();
	}
	return root;
}

/*
��������ǰ�����
*/
void qianxu(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		printf("%d\t", node->m_nValue);
		qianxu(node->m_pLeft);
		qianxu(node->m_pRight);
	}

}

/*
���������������
*/
void zhongxu(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		zhongxu(node->m_pLeft);
		//cout << node->m_nValue << "  ";
		printf("%d\t", node->m_nValue);
		zhongxu(node->m_pRight);
	}

}

/*
�������ĺ������
*/
void houxu(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		houxu(node->m_pLeft);
		houxu(node->m_pRight);
		printf("%d\t", node->m_nValue);
	}

}

int main(void)
{
	BinaryTreeNode* root = createBiTree();

	cout << "ǰ�������";
	qianxu(root);
	cout << endl;

	cout << "���������";
	zhongxu(root);
	cout << endl;

	cout << "���������";
	houxu(root);
	cout << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

