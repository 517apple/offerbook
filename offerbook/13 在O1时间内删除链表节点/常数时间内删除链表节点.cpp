#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
struct与class的区别：
1. 默认的权限不一样，struct默认public，class默认private，包括成员权限与继承权限
2. 在没有构造函数的情况下，struct可用{}进行初始化，而class则需要在成员都是public的情况下才可以这样。
3. C语言是面向过程的，数据与操作分离，所以才struct当中不能直接定义函数（可以通过包含函数指针的方式）；C++中的类是面向对象的
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

class TEST {
	int a;//默认的访问权限是private
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

