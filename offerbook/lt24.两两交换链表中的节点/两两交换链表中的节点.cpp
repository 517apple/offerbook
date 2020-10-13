#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

/*
https://leetcode-cn.com/problems/swap-nodes-in-pairs/
˼·�� 
1�� ÿ�α��������ڵ㣬��Ҫ����������ڵ�ĵ�ַ�������ڵ�֮�ϵ��Ǹ��ڵ�
2�� �����ڵ��
*/

ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newhead = head->next;

	//���е�һ�ν���
	ListNode* leftnode, * rightnode;
	leftnode = head;
	head->next->next = head;
	while (leftnode->next && leftnode->next->next)//ÿ�α��������ڵ�
	{
		ListNode* n1, * n2;
		n1 = leftnode->next;
		n2 = n1->next;
		n1->next = n2->next;
		n2->next = n1;
		leftnode->next = n2;
		leftnode = n1;
	}
	return newhead;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

