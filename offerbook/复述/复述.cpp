#define _CRT_SECURE_NO_WARNINGS
//�������Ľ����㷨
#include <iostream>
using namespace std;
typedef struct node {
	int data;
	struct node* lchild;
	struct node* rchild;
}Node, * BTnode;
//�����㷨
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
	cout << "�����ɹ�" << endl;
	preorder(T);
	system("pause");

}
