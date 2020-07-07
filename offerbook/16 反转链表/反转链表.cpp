#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>

using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

/*
建立链表
*/
ListNode* Creat_ListNode()
{
	ListNode* head, * p1, * p2;
	p1 = p2 = head = new ListNode;
	head->m_pNext = NULL;
	for (size_t i = 10; i > 0; i--)
	{
		p1 = new ListNode;
		p1->m_nKey = i;
		p1->m_pNext = NULL;
		if (head->m_pNext == NULL)
		{
			head->m_pNext = p1;
			p2 = p1;
		}
		else
		{
			p2->m_pNext = p1;
			p2 = p1;
		}
	}
	return head;
}


/*
打印链表
*/
void PrintList(ListNode* pHead)
{
	if (pHead == NULL)
		return;

	ListNode* node;

	node = pHead->m_pNext;

	while (node != NULL)
	{
		cout << node->m_nKey << "  ";
		node = node->m_pNext;
	}

}

/*
反转链表
*/
ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL || pHead->m_pNext==NULL)
		return pHead;

	ListNode* head, * p1, * p2;
	p1 = p2 = head = new ListNode;
	pHead = pHead->m_pNext;
	head->m_pNext = NULL;
	while(pHead!=NULL)
	{
		p1 = new ListNode;
		p1->m_nKey = pHead->m_nKey;
		p1->m_pNext = NULL;
		if (head->m_pNext == NULL)
		{
			head->m_pNext = p1;
			p2 = p1;
		}
		else
		{
			p2->m_pNext = p1;
			p2 = p1;
		}
		pHead = pHead->m_pNext;
	}

	return head;

}


/*
反转链表
*/
ListNode* ReverseList1(ListNode* pHead)
{
	if (pHead == NULL || pHead->m_pNext == NULL)
		return pHead;

	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;	
	while (pNode!=NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNode == pHead)
			pNext->m_pNext = NULL;

		if (pNext==NULL)
		{
			pReversedHead = pNode;
		}
		pPrev = pNode;
		pNode = pNext;
	}
	ListNode* Rhead = new ListNode;
	Rhead->m_pNext = pReversedHead;
	return Rhead;
}

/*
反转链表：尝试使用栈的方式来实现

*/
ListNode* ReverseList2(ListNode* pHead)
{
	if (pHead == NULL || pHead->m_pNext == NULL)
		return pHead;

	stack<int> s;
	pHead = pHead->m_pNext;
	while (pHead!=NULL)
	{
		s.push(pHead->m_nKey);
		pHead = pHead->m_pNext;
	}

	ListNode* head, * p1, * p2;
	p1 = p2 = head = new ListNode;
	head->m_pNext = NULL;
	while(!s.empty())
	{
		p1 = new ListNode;
		p1->m_nKey = s.top();
		s.pop();
		p1->m_pNext = NULL;
		if (head->m_pNext == NULL)
			head->m_pNext = p1;
		else
			p2->m_pNext = p1;

		p2 = p1;
	}
	return head;
	
}

int main(void)
{
	ListNode* head,*head1;

	head = Creat_ListNode();
	PrintList(head);
	cout << endl;
	head1 = ReverseList2(head);
	PrintList(head1);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

