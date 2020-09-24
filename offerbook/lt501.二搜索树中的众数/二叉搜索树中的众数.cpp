#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

//二叉树的建树算法
TreeNode* CreatTree()
{
	TreeNode* root;
	int ch;
	cin >> ch;
	if (ch == 0)
	{
		root = NULL;
	}
	else
	{
		root = new TreeNode((int)ch);
		root->left = CreatTree();
		root->right = CreatTree();
	}
	return root;
}

vector<int> zhongxu(TreeNode* root) {
	static vector<int> arr;
	if (root != NULL)
	{
		zhongxu(root->left);
		arr.push_back(root->val);
		zhongxu(root->right);
	}
	return arr;
}

vector<int> findMode(TreeNode* root) {
	vector<int> res;
	vector<int> arr = zhongxu(root);
	int maxk = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		int k = 1;
		while ((i < arr.size() - 1) && (arr[i] == arr[i + 1]))
		{
			k++;
			i++;
		}
		if (k > maxk)
		{
			res.clear();
			res.push_back(arr[i]);
		}
		if (k == maxk)
		{
			res.push_back(arr[i]);
		}
	} 
	return res;
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x == 0)
		return true;

	long a = 0, b = x;
	while (b)
	{
		a = a * 10 + b % 10;
		b /= 10;
	}
	if (a == x)
		return false;
	else
		return true;
}


int main(void)
{
	isPalindrome(121);
	cout << "hello world" << endl;
	system("pause");
	return 0;

}

