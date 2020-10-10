#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};


/*
* 
* https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
�����˼·���Ǻܼ򵥵ģ����α�������һ������n����Ȼ��һ���ߣ�֪�����ߵĵ��������β�ڵ�

*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* fast, * slow, * ret;
	ret = fast = slow = head;
	while (n--)
		fast = fast->next;
	while (fast && fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	if ((slow == head)&&(fast==NULL))
		ret = slow->next;
	else
		slow->next = slow->next->next;

	return ret;
}




int main(void)
{
	int n = 1;
	while (n--)
	{
		cout << n << endl;
	}

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

