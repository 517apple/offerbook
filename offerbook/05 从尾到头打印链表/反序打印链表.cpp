#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>


using namespace std;

/*
������5�������ӡ����
������Ľṹ��ջ�Ĳ�������Ϥ
*/

/*
ջ��
���ò�����
1. ��ջ��s.pop()
2. ѹջ��s.push()
3. ��ջ�Ĵ�С��s.size()
4. �ж�ջ�Ƿ�Ϊ�գ�s.empty()
5. ��ȡջ��Ԫ�ص�ֵ��s.top()
*/
//����ṹ
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



int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

