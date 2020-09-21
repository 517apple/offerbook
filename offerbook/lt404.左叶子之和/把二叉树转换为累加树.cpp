#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

������������������մ�С�����˳������
eg:  2 5 13
�õ����нڵ�֮��sum��Ȼ����ʹ�������������ȥ��һ���ڵ����ֵ���ǵ�ǰ�ڵ����ֵ����һ����0��ʼ

!! ������о���static���÷�Ҫ�������ύ�𰸵�ʱ��Ŀ��ܲ���Ԥ�ڵĽ��
*/


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};



//�����㷨
TreeNode* CreatTree()
{
	TreeNode* root;  //����һ��ָ���������ָ��
	int ch;
	cin >> ch;
	if (ch == 0)
		root = NULL;
	else
	{
		//�����Ϊ�գ��ٴ���һ���µĽڵ㣬Ȼ����rootָ����
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
�������½ڵ��ֵ=��ֵ+��һ�ڵ��ֵ����ʼֵΪ0��
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

