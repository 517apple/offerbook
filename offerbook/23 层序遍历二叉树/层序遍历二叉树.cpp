#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <deque>

using namespace std;


/*
1. ��Ϊ������ӡ��ʱ����жϽڵ�����ҽڵ��Ƿ�Ϊ�գ�����ֱ�Ӿ͸�һ��Ĭ�ϵĿ�ָ��
2. �������֮�󲻻�Ĭ�ϳ�ʶ��Ϊ0��������VS���ﲻ��
3. ��δ���һ�����ķ�������Ҫ����
*/
struct BinaryTreeNode
{
	int m_nValue=0;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
};


/*
�Լ���˼·��ʹ��������vector����
���õĲ�����vtree.empty()!=NULL    ���շ���false  �ȼ���null
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
ʹ��dequeʵ��
1. BinaryTreeNode* pNode = root;  ������䲢û�д���һ���µĽڵ㣬����ʹһ��ָ�����ָ����һ���Ѿ����ڵĽڵ�
�ڴ�����ʱ��Ҫע�⣬������������ջ
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
	int a;//a��û�б���ʼ��Ϊ0

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

