#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
/*
思路：
由于我们知道被删除节点的下一节点的地址，所以可以用被删节点替代它的下一个节点
再将下一个节点删除，效果等价

特殊情况：
1. 只有一个节点时，删除之后要将指针指向null
2. 被删节点是尾节点时，此时需使用遍历的方法
*/
void DeleteNode(ListNode** PListHead , ListNode* pToBeDeleted)
{
	if (!pToBeDeleted || !PListHead)
		return;
	//如果只有一个节点
	if (pToBeDeleted == *PListHead)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*PListHead = NULL;
	}
	//要删除的是尾节点，遍历
	else if (pToBeDeleted->m_pNext==NULL)
	{
		ListNode *pNode = *PListHead;
		while (pNode->m_pNext == pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
	//一般情况，删除的是链表内的节点
	else
	{
		ListNode* pNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNode->m_nValue;
		pToBeDeleted->m_pNext = pNode->m_pNext;

		delete pNode;
		pNode = NULL;

	}
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

