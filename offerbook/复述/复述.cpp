#define _CRT_SECURE_NO_WARNINGS
//二叉树的建立算法
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
}Node, * BTnode;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int deeplen = 0;
		deque<TreeNode*> detree;
		detree.push_back(root);
		vector<int> v1;
		while (detree.size())
		{
			TreeNode* node = detree.front();
			v1.push_back(node->val);
			if (node->left != NULL)
				detree.push_back(node->left);
			else
				v1.push_back(node->val);

			if (node->right != NULL)
				detree.push_back(node->right);
			else
				v1.push_back(node->val);

			if ((node->right == NULL) && (node->left == NULL))
				return

		}

	}
};



//建树算法
Node* createBiTree() {
	BTnode root;
	int ch;
	cin >> ch;
	if (ch == 0)
		root = NULL;
	else {
		root = new node;
		root->data = ch;
		root->lchild = createBiTree();
		root->rchild = createBiTree();
	}
	return root;
}
void preorder(struct node* root) {
	if (root) {
		cout << root->data << " ";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
int main() {
	BTnode T;
	T = NULL;
	T = createBiTree();
	cout << "建树成功" << endl;
	preorder(T);
	system("pause");

}
