#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
struct��class������
1. Ĭ�ϵ�Ȩ�޲�һ����structĬ��public��classĬ��private��������ԱȨ����̳�Ȩ��
2. ��û�й��캯��������£�struct����{}���г�ʼ������class����Ҫ�ڳ�Ա����public������²ſ���������
3. C������������̵ģ�������������룬���Բ�struct���в���ֱ�Ӷ��庯��������ͨ����������ָ��ķ�ʽ����C++�е�������������
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

class TEST {
	int a;//Ĭ�ϵķ���Ȩ����private
};
/*
˼·��
��������֪����ɾ���ڵ����һ�ڵ�ĵ�ַ�����Կ����ñ�ɾ�ڵ����������һ���ڵ�
�ٽ���һ���ڵ�ɾ����Ч���ȼ�

���������
1. ֻ��һ���ڵ�ʱ��ɾ��֮��Ҫ��ָ��ָ��null
2. ��ɾ�ڵ���β�ڵ�ʱ����ʱ��ʹ�ñ����ķ���
*/
void DeleteNode(ListNode** PListHead , ListNode* pToBeDeleted)
{
	if (!pToBeDeleted || !PListHead)
		return;
	//���ֻ��һ���ڵ�
	if (pToBeDeleted == *PListHead)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*PListHead = NULL;
	}
	//Ҫɾ������β�ڵ㣬����
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
	//һ�������ɾ�����������ڵĽڵ�
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

