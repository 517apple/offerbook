#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <deque>
#include <vector>
#include <string>

using namespace std;

/*
��ϰ��������һЩ���ò���������������ǰ�к���������������
ͬʱ����Եݹ���������
*/

struct BinTreeNode
{
	int val = 0;
	BinTreeNode* pLeft = NULL;
	BinTreeNode* pRight = NULL;
};

/*
�����㷨��
1. ʹ�ü������붯̬����
2. ʹ��������ٽ���������֤
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
ǰ�����
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
���������ӡ��
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
������������·��
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

	cout << "--------------�ָ���-------------" << endl;
	vector<string> paths;
	string path = "";
	construct_paths(root, path, paths);
	
	//������������ʽ
#if 0
	for (vector<string>::iterator iter=paths.begin();iter!=paths.end();iter++)
	{
		cout << *iter << endl;
	}
#else
	//ͨ�������±����
	for (size_t i = 0; i < paths.size(); i++)
	{
		cout << paths.at(i) << endl;
	}

#endif


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

