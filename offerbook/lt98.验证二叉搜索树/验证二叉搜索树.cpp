#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;



/*
https://leetcode-cn.com/problems/validate-binary-search-tree/.

˼·������
1�� ���ݶ��������������˳�����Ӧ�þ���һ����С���������
2�� ����������ʣ����������������ʱ�򽫵�ǰ�ڵ����ֵ����һ���ڵ����ֵ���бȽ�
3�� ���������һ���ڵ����ֵ������Լ���������������ֹ����������false

Q:��һ���ڵ��ֵ��˭�Ƚϣ�

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

