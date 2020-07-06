#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>

using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* head, unsigned int k)
{
	if (head == NULL || k == 0)
		return NULL;

	ListNode* FrontNode = head;
	ListNode* BackNode = head;
	int k1 = 0;
	while (k1<k-1)
	{
		k1++;
//此处还应该加入判断的代码
		if(FrontNode->m_pNext!=NULL)
			FrontNode = FrontNode->m_pNext;
		else
			return NULL;
	}
	while (FrontNode->m_pNext!=NULL)
	{
		FrontNode = FrontNode->m_pNext;
		BackNode = BackNode->m_pNext;
	}

	return BackNode;
}

/*
建立链表
*/
ListNode* Creat_ListNode()
{
	ListNode * head, * p1, * p2;
	p1=p2=head = new ListNode;
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
2020-7-6 15:23:08
反序打印链表这个函数没有正确的执行？
*/
void PrintList(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = new ListNode;
	pNode = pHead;

	while (pNode->m_pNext != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (nodes.empty())
	{
		cout << nodes.top()->m_nKey << "  ";
		nodes.pop();
	}
	cout << endl;
}

int main(void)
{
	ListNode *head,*node;

	head = Creat_ListNode();
	node = new ListNode;
	node->m_pNext = NULL;
	if(head!=NULL)
		node = head->m_pNext;

	while(node->m_pNext!=NULL)
	{
		cout << node->m_nKey << "  ";
		node = node->m_pNext;
	}
	cout << node->m_nKey << endl;

	PrintList(head);


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

