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
��������
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
��ӡ����
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
��ת����
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
��ת�������ս�ָoffer��
1. ֮ǰ�����ԭ�������ڸ�ֵ��ʱ���Ѿ��ƻ���ԭ��������
2. �÷�������ԭ������Ļ����Ͻ��еģ��ƻ���ԭ��������
3. ��������ͷ���Ҳ�������ݵĻ���������Ҫ�Լ��޸�
*/
ListNode* ReverseList1(ListNode* pHead)
{
	if (pHead == NULL || pHead->m_pNext == NULL)
		return pHead;

	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead->m_pNext;
	ListNode* pPrev = NULL;	
	while (pNode!=NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		
		pNode->m_pNext = pPrev;

		pPrev = pNode;
		pNode = pNext;
		
	}
	ListNode* Rhead = new ListNode;
	Rhead->m_pNext = pPrev;
	return Rhead;
}

/*
��ת��������ʹ��ջ�ķ�ʽ��ʵ��

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
	head1 = ReverseList1(head);
	PrintList(head1);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

