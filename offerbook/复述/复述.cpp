#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
不借助新的空间实现链表的反转
*/

struct ListNode
{
	int val=0;
	ListNode* next=NULL;
};


ListNode* rev(ListNode* head)
{
	if (head == NULL)
		return NULL;

	ListNode* NewHead = NULL;
	ListNode* CurNode = head;
	ListNode* OldHead = head;
	while (OldHead!=NULL)
	{
		CurNode = OldHead;
		OldHead = OldHead->next;
		CurNode->next = NewHead;
		NewHead = CurNode;
	}
	return NewHead;
}

void PrintNL(ListNode* head)
{
	if (head == NULL)
		return;

	while (head!=NULL)
	{
		printf("%d\t", head->val);
		head = head->next;
	}
	printf("\n");
}



int main(void)
{
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;

	a.val = 1;
	a.next = &b;
	b.val = 2;
	b.next = &c;
	c.val = 3;
	c.next = &d;
	d.val = 4;
	d.next = &e;
	e.val = 5;
	e.next = NULL;

	PrintNL(&a);

	ListNode* node;
	node = rev(&a);
	PrintNL(node);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

