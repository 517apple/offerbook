#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

//二叉树结点定义
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*
Q:已知前序和中序遍历的序列，重建出该二叉树
A:
1. 根据前序遍历的第一个节点为root节点，从中序遍历序列中分辨出左右子树所包含的元素
2. 循环递归，从而确定树的结构

2020-7-4 22:01:04
此处代码暂未完成，择日再战
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
	//*s  等价于  s[0]
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

