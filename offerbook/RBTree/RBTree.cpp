#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
1. 首先学习到的是原地算法，尾部递归

*/

#define BALCK 1
#define RED 0

class bst
{
public:
	bst();
	~bst();

private:
	struct Node {
		int value;
		bool color;
		Node *leftTree, * rightTree, * parent;

		Node() :value(0), color(RED), leftTree(NULL), rightTree(NULL), parent(NULL) {}

		Node* grandparent() {
			if (parent == NULL)
				return NULL;
			else
			{
				return parent->parent;
			}
		}

		//返回叔叔节点


		//返回兄弟节点


		//右旋
		Node* rotate_right(Node *p)
		{
		
		}

		//左旋
		Node* rotate_left(Node *p)
		{
		
		}






	};
};

bst::bst()
{
}

bst::~bst()
{
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

