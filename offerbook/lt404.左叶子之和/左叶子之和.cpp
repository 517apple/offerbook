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
		root->val=(int)ch;
		root->left = CreatTree();
		root->right = CreatTree();
	}
	return root;
}

//�������
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

