#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>
#include <vector>


/*
二叉树的一些常规操作：
1. 创建
2. 遍历（前中后序遍历）

参考链接1：https://blog.csdn.net/qq_40693171/article/details/99745321
*/
using namespace std;

struct BinaryTreeNode
{
	int m_nValue = 0;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
};

//建树算法
BinaryTreeNode* createBiTree() {
	BinaryTreeNode* root;
	int ch;
	cin >> ch;
	if (ch == 0)
		root = NULL;
	else {
		root = new BinaryTreeNode;
		root->m_nValue = (int)ch;
		root->m_pLeft = createBiTree();
		root->m_pRight = createBiTree();
	}
	return root;
}

//建树算法
vector<int> nums = { 1,2,4,0,0,5,0,0,3,0,0 };
int index = 0;
BinaryTreeNode* createBiTree1() {

	BinaryTreeNode* root;
	int ch=nums[index++];
	if (ch == 0)
		root = nullptr;
	else {
		root = new BinaryTreeNode;
		root->m_nValue = ch;
		root->m_pLeft = createBiTree1();
		root->m_pRight = createBiTree1();
	}
	return root;
}

/*
二叉树的前序遍历
*/
void qianxu(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		printf("%d\t", node->m_nValue);
		qianxu(node->m_pLeft);
		qianxu(node->m_pRight);
	}

}

/*
非递归前序：用栈
*/

void qianxu1(BinaryTreeNode* root)
{
	stack<BinaryTreeNode*> s;
	if (root)
		s.push(root);
	while (!s.empty())
	{
		BinaryTreeNode* node = s.top();
		s.pop();
		cout << node->m_nValue << " ";
		if (node->m_pRight)
			s.push(node->m_pRight);
		if (node->m_pLeft)
			s.push(node->m_pLeft);
	}
}




/*
二叉树的中序遍历
*/
void zhongxu(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		zhongxu(node->m_pLeft);
		//cout << node->m_nValue << "  ";
		printf("%d\t", node->m_nValue);
		zhongxu(node->m_pRight);
	}

}

/*
二叉树的后序遍历
*/
void houxu(BinaryTreeNode* node)
{
	if (node != NULL)
	{
		houxu(node->m_pLeft);
		houxu(node->m_pRight);
		printf("%d\t", node->m_nValue);
	}

}

/*
层序遍历
*/
void cengxu(BinaryTreeNode* root)
{
	deque<BinaryTreeNode*> dq;
	if (root)
		dq.push_back(root);
	while (!dq.empty())
	{
		BinaryTreeNode* node = dq.front();
		dq.pop_front();
		cout << node->m_nValue << " ";
		if (node->m_pLeft)
			dq.push_back(node->m_pLeft);
		if (node->m_pRight)
			dq.push_back(node->m_pRight);
	}
}

int main(void)
{
	BinaryTreeNode* root = createBiTree1();

	cout << "前序遍历：";
	qianxu(root);
	cout << endl;



	cengxu(root);
	cout << endl;

	deque<int> dd={1,2,3,4};
	for (auto x : dd)
		cout << x << " ";
	cout << endl;
	cout << "size:"<<dd.size()<<"  1:"<<dd[1] << endl;
	dd.push_front(0);
	cout << "size:" << dd.size() << "  1:" << dd[1] << endl;

	cout << "size:" << dd.max_size() << "  1:" << endl;
	dd.insert(dd.begin()+2, -1);
	for (auto x : dd)
		cout << x << " ";
	cout << endl;
	try
	{
		cout << dd.at(8) << " ";
	}
	catch (const std::exception& e1)
	{
		cout << e1.what() << endl;
	}
	cout << nums.capacity() << endl;
	nums.push_back(12);
	cout << nums.capacity() << endl;
	

	//cout << "中序遍历：";
	//zhongxu(root);
	//cout << endl;

	//cout << "后序遍历：";
	//houxu(root);
	//cout << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

