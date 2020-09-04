#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <deque>
#include <vector>
#include <string>

using namespace std;

/*
复习二叉树的一些常用操作，包括建树、前中后序遍历、层序遍历
同时加深对递归迭代的理解
*/

struct BinTreeNode
{
	int val = 0;
	BinTreeNode* pLeft = NULL;
	BinTreeNode* pRight = NULL;
};

/*
建树算法：
1. 使用键盘输入动态建树
2. 使用数组快速建树进行验证
*/

BinTreeNode* CreateTree()
{
	BinTreeNode* root=new BinTreeNode;
	int ch;
	cin>>ch;
	if (ch == 0)
		root = NULL;
	else
	{
		root->val = (int)ch;
		root->pLeft = CreateTree();
		root->pRight = CreateTree();
	}
	return root;
}

/*
前序遍历
*/
void qianxu(BinTreeNode* root) 
{
	if (root == NULL)
		return;
	cout << root->val<<" ";
	qianxu(root->pLeft);
	qianxu(root->pRight);
}

/*
层序遍历打印树
*/
void printTree(BinTreeNode* root)
{
	deque<BinTreeNode*> detree;
	if (root == NULL)
		return;
	else
		detree.push_back(root);

	while (detree.size())
	{
		BinTreeNode* CurNode;
		CurNode = detree.front();
		cout << CurNode->val << " ";
		if (CurNode->pLeft != NULL)
			detree.push_back(CurNode->pLeft);
		if (CurNode->pRight != NULL)
			detree.push_back(CurNode->pRight);

		detree.pop_front();
	}
	cout << endl;
}


/*
二叉树的所有路径
*/
void construct_paths(BinTreeNode* root, string path, vector<string>& paths)
{
	if (root == NULL)
		return;

	path += to_string(root->val);
	if (root->pLeft == NULL && root->pRight == NULL)
	{
		paths.push_back(path);
	}
	else
	{
		path += "->";
		construct_paths(root->pLeft, path, paths);
		construct_paths(root->pRight, path, paths);
	}

}


int main(void)
{
	BinTreeNode* root = CreateTree();
	printTree(root);
	qianxu(root);
	cout << endl;

	cout << "--------------分割线-------------" << endl;
	vector<string> paths;
	string path = "";
	construct_paths(root, path, paths);
	
	//迭代器遍历方式
#if 0
	for (vector<string>::iterator iter=paths.begin();iter!=paths.end();iter++)
	{
		cout << *iter << endl;
	}
#else
	//通过数组下标遍历
	for (size_t i = 0; i < paths.size(); i++)
	{
		cout << paths.at(i) << endl;
	}

#endif


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

