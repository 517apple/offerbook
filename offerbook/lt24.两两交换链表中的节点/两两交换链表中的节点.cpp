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
思路： 
1、 每次遍历两个节点，需要保存第三个节点的地址和两个节点之上的那个节点
2、 两个节点的
*/

ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newhead = head->next;

	//进行第一次交换
	ListNode* leftnode, * rightnode;
	leftnode = head;
	head->next->next = head;
	while (leftnode->next && leftnode->next->next)//每次遍历两个节点
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

