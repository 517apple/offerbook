#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <deque>
#include <stack>

using namespace std;

/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

我的思路是使用两个队列，一个存储当前节点，另一个队列存储下一个序列的节点

*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


vector<vector<int>> levelOrderBottom(TreeNode* root) {
	

	deque<TreeNode*> curdenode, nextdenode;
	vector<vector<int>> tarvec;
	stack<vector<int>> stackvec;
	
	if(root!=NULL)
		curdenode.push_back(root);

	while (curdenode.size())
	{
		vector<int> vec;
		while (curdenode.size())
		{
			vec.push_back(curdenode.front()->val);
			if (curdenode.front()->left != NULL)
				nextdenode.push_back(curdenode.front()->left);
			if (curdenode.front()->right != NULL)
				nextdenode.push_back(curdenode.front()->right);
			curdenode.pop_front();
		}
		stackvec.push(vec);
		//tarvec.push_back(vec);
		curdenode = nextdenode;
		nextdenode.clear();
	}

	while (stackvec.size())
	{
		tarvec.push_back(stackvec.top());
		stackvec.pop();
	}
	//可以使用reverse函数
	return tarvec;

}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

