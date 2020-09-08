#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <deque>
#include <stack>

using namespace std;

/*
����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

�ҵ�˼·��ʹ���������У�һ���洢��ǰ�ڵ㣬��һ�����д洢��һ�����еĽڵ�

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
	//����ʹ��reverse����
	return tarvec;

}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

