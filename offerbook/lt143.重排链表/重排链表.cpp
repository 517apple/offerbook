#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <deque>


using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};


/*
https://leetcode-cn.com/problems/reorder-list/

思路1：使用deque
思路2：使用快慢指针找到中点，拆成两个链表之后进行合并


*/





void reorderList(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return;
	deque<ListNode*> de;
	ListNode* node = head;
	while (node)
	{
		de.push_back(node);
		node = node->next;
	}
	node = head;
	de.pop_front();
	bool flag = false;//从队列前面取数据
	while (!de.empty())
	{
		if (flag)
		{
			node->next = de.front();
			de.pop_front();
			flag = false;
		}
		else
		{
			node->next = de.back();
			de.pop_back();
			flag = true;
		}
		node = node->next;
	}
	node->next = nullptr;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

