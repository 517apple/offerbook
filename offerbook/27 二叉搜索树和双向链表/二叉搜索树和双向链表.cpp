#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 


/*
输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
不能创建任何新的结点，只能调整树中结点指针的指向。
参考链接1：https://blog.csdn.net/qq_40693171/article/details/99745321
*/
using namespace std;

struct BinaryTreeNode
{
	int m_nValue = 0;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
};

//建树算法
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
二叉树的前序遍历
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
二叉树的中序遍历
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
二叉树的后序遍历
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

	cout << "前序遍历：";
	qianxu(root);
	cout << endl;

	cout << "中序遍历：";
	zhongxu(root);
	cout << endl;

	cout << "后序遍历：";
	houxu(root);
	cout << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

