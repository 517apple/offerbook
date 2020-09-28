#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;



/*
https://leetcode-cn.com/problems/validate-binary-search-tree/.

思路分析：
1， 根据二叉树的中序遍历顺序出来应该就是一个从小到大的排序
2， 根据这个性质，可以在中序遍历的时候将当前节点的数值与上一个节点的数值进行比较
3， 如果大于上一个节点的数值，则可以继续迭代；否则终止迭代，返回false

Q:第一个节点的值与谁比较？

*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

bool first = true;
bool ans = true;
int beforval = 0;

void inoder(TreeNode* root)
{
    if (root != NULL)
    {
        isValidBST(root->left);

        if (first == true)
        {
            first = false;
            beforval = root->val;
        }
        else
        {
            //cout << root->val<<"  :  "<< beforval<<endl;
            if (root->val <= beforval)
            {
                ans = false;
                return;
            }
            else
            {
                beforval = root->val;
                //cout <<"  :  "<<endl;
            }
        }
        isValidBST(root->right);
    }
}


bool isValidBST(TreeNode* root) {
    inoder(root);
    return ans;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

