#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>


using namespace std;

/*
面试题5：反序打印链表
对链表的结构和栈的操作不熟悉
*/

/*
栈：
常用操作：
1. 弹栈：s.pop()
2. 压栈：s.push()
3. 求栈的大小：s.size()
4. 判断栈是否为空：s.empty()
5. 获取栈顶元素的值：s.top()
*/
//链表结构
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void PrintList(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode->m_pNext != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (nodes.empty())
	{
		cout << nodes.top()->m_nKey << endl;
		nodes.pop();
	}
}

/*
函数调用自身
函数循环对自身就行嵌套应该会消耗很多的内存资源的，每调用一次自身都会开辟调用该函数所需的资源

*/
int sum(int num)
{
	static int x = 0;
	int s;
	x++;
	if (num <= 1)
		return 1;
	else
	{
		cout << "第" << x << "次调用" << endl;
		
		s= num + sum(num - 1);
	}
	return s;
}

int main(void)
{
	cout << sum(5) << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}


