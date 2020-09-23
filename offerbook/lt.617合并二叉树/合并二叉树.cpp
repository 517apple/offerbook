#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
https://leetcode-cn.com/problems/merge-two-binary-trees/
*/


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

/*
模仿建树算法，此程序暂时不全
*/
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	TreeNode* root;
	if (t1 == NULL && t2 == NULL)
		root = NULL;

	if (t1 != NULL || t2 != NULL)
	{
		root = new TreeNode(0);
		if (t1 != NULL && t2 != NULL)
		{
			root->val = t1->val + t2->val;
			mergeTrees(t1->left, t2->left);
			mergeTrees(t1->right, t2->right);
		}
			
		if (t1 != NULL && t2 == NULL)
		{
			root->val = t1->val;
			mergeTrees(t1->left, t2);
			mergeTrees(t1->right, t2);
		}
			
		if (t1 == NULL && t2 != NULL)
		{
			root->val = t2->val;
			mergeTrees(t1, t2->left);
			mergeTrees(t1, t2->right);
		}
	}

	return root;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

