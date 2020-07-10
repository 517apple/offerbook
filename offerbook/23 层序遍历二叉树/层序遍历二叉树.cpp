#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <deque>

using namespace std;


/*
1. 因为遍历打印的时候会判断节点的左右节点是否为空，所以直接就给一个默认的空指针
2. 定义变量之后不会默认初识化为0，至少在VS这里不是
3. 如何创建一棵树的方法后期要补充
*/
struct BinaryTreeNode
{
	int m_nValue=0;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
};


/*
自己的思路，使用了两个vector容器
误用的操作：vtree.empty()!=NULL    不空返回false  等价于null
*/
void PrintTree(BinaryTreeNode* tree)
{
	if (tree == NULL)
		return;
	vector<BinaryTreeNode*> vtree;
	vtree.push_back(tree);
//	while (!vtree.empty())
	while (vtree.size())
	{
		vector<BinaryTreeNode*> NextLevelData;
		for (size_t i = 0; i < vtree.size(); i++)
		{
			cout << vtree[i]->m_nValue << ",";
			if (vtree[i]->m_pLeft)
				NextLevelData.push_back(vtree[i]->m_pLeft);
			if (vtree[i]->m_pRight)
				NextLevelData.push_back(vtree[i]->m_pRight);
		}
		vtree.clear();
		//if(!NextLevelData.empty())
		//	vtree.swap(NextLevelData);
		vtree = NextLevelData;
	}
}

/*
使用deque实现
1. BinaryTreeNode* pNode = root;  这种语句并没有创建一个新的节点，而是使一个指针变量指向了一个已经存在的节点
在创建的时候要注意，无论是树还是栈
*/
void PrintTree1(BinaryTreeNode* root)
{
	if (root==NULL)
		return;
	
	deque<BinaryTreeNode*> deTree;
	deTree.push_back(root);
	while (deTree.size())
	{
		cout << deTree.front()->m_nValue << " ";
		if (deTree.front()->m_pLeft)
			deTree.push_back(deTree.front()->m_pLeft);
		if (deTree.front()->m_pRight)
			deTree.push_back(deTree.front()->m_pRight);

		deTree.pop_front();
	}

}

int main(void)
{
	int a;//a并没有被初始化为0

	BinaryTreeNode* root=new BinaryTreeNode;
	root->m_nValue = 10;

	BinaryTreeNode* pleft = new BinaryTreeNode;
	pleft->m_nValue = 11;
	root->m_pLeft=pleft;


	BinaryTreeNode* pright = new BinaryTreeNode;
	pright->m_nValue = 12;
	root->m_pRight=pright;



	PrintTree1(root);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

