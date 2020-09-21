#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

中序遍历，二叉树按照从小到大的顺序排列
eg:  2 5 13
得到所有节点之和sum，然后再使用中序遍历，减去上一个节点的数值就是当前节点的数值，第一个从0开始

!! 在领扣中尽量static的用法要谨慎，提交答案的时候的可能不是预期的结果
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
		root->val = (int)ch;
		root->left = CreatTree();
		root->right = CreatTree();
	}
	return root;
}



int zhongxusum(TreeNode* root) {
	 static int sum = 0;

	if (root != NULL)
	{
		zhongxusum(root->left);
		sum += root->val;
		zhongxusum(root->right);
	}

	return sum;

}

void convert(TreeNode* root, int sum, int oldvalue)
{
	static int ressum = sum, oldnodevalue = oldvalue;

	if (root != NULL)
	{
		convert(root->left, 0, 0);
		oldnodevalue = root->val;
		root->val = ressum;
		ressum -= oldnodevalue;
		convert(root->right, 0, 0);
	}
}

TreeNode* convertBST1(TreeNode* root) {
	int sum = zhongxusum(root);

	convert(root, sum, 0);

	return root;
}

void reversezhongxu(TreeNode* root) {


}

/*
反中序，新节点的值=旧值+上一节点的值（初始值为0）
*/
TreeNode* convertBST(TreeNode* root) {
	static int oldnodeval = 0;
	if (root != NULL)
	{
		convertBST(root->right);
		root->val = root->val + oldnodeval;
		oldnodeval = root->val;
		convertBST(root->left);
	}
	return root;
}



int main(void)
{
	TreeNode* root = CreatTree();
	root = convertBST(root);

	//cout << sum << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

