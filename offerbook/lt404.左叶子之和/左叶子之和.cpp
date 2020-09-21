#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
https://leetcode-cn.com/problems/sum-of-left-leaves/
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


//建树算法
TreeNode* CreatTree()
{
	TreeNode* root;  //定义一个指向二叉树的指针
	int ch;
	cin >> ch;
	if (ch == 0)
		root = NULL;
	else
	{
		//如果不为空，再创建一个新的节点，然后让root指向它
		root = new TreeNode(0);
		root->val=(int)ch;
		root->left = CreatTree();
		root->right = CreatTree();
	}
	return root;
}

//中序遍历
int zhongxu(TreeNode* root)
{
	static int sum = 0;
	if (root != NULL)
	{
		zhongxu(root->left);
		if (root->left == NULL && root->right == NULL)
			sum += root->val;
		zhongxu(root->right);
	}
	return sum;
}

int sumOfLeftLeaves(TreeNode* root) {
	int sum = 0;

	return 0;
}



int main(void)
{
	TreeNode* root = CreatTree();
	int sum = zhongxu(root);
	cout << "sum = " << sum << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

