#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <string>
#include <deque>

using namespace std;



struct BintreeNode
{
	int val = 0;
	BintreeNode* pLeft = NULL;
	BintreeNode* pRight = NULL;
};


/*
建树
*/
BintreeNode* CreateTree()
{
	BintreeNode* node = new BintreeNode;
	int ch;
	cin >> ch;
	if (ch == 0)
		node = NULL;
	else
	{
		
		node->val = (int)ch;
		node->pLeft = CreateTree();
		node->pRight=CreateTree();
	}

	return node;
}

/*
层序遍历打印树
*/
void printTree(BintreeNode* root)
{
	if (root == NULL)
		return;
	cout << "--------------遍历树-------------" << endl;
	deque<BintreeNode*> detree;
	detree.push_back(root);
	while (detree.size())
	{
		cout << detree.front()->val << " ";
		if (detree.front()->pLeft != NULL)
			detree.push_back(root->pLeft);
		if (detree.front()->pRight != NULL)
			detree.push_back(root->pRight);

		detree.pop_front();
	}
	cout << endl;

}

/*
前序遍历
*/
void qianxu(BintreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << " ";
	qianxu(root->pLeft);
	qianxu(root->pRight);
}


/*
二叉树的所有路径
*/
void construct_path(BintreeNode* root, string path, vector<string>& paths)
{
	if (root == NULL)
		return;
	path += to_string(root->val);
	if (root->pLeft==NULL && root->pRight==NULL)
	{
		paths.push_back(path);
	}
	else
	{
		path += "->";
		construct_path(root->pLeft, path, paths);
		construct_path(root->pRight, path, paths);
	}

}

int main(void)
{
	BintreeNode* root = CreateTree();

	/*qianxu(root);
	printTree(root);*/

	string path = "";
	vector<string> paths;

	construct_path(root, path, paths);

	for (vector<string>::iterator iter=paths.begin();iter!=paths.end();iter++)
	{
		cout << *iter << endl;
	}

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

