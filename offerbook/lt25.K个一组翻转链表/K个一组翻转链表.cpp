#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};


ListNode* reverseKGroup(ListNode* head, int k) {
    stack<ListNode*> stk;
    ListNode* cur = head;
    ListNode* dummynode = new ListNode(0);
    ListNode* now = dummynode;
    while (cur != nullptr)
    {
        ListNode* node = cur;
        int i = 0;
        for (; i < k; i++)
        {
            if (node)
            {
                stk.push(node);
                //cout<<node->val<<":"<<i<<endl;
                node = node->next;
            }
            else
            {
                //cout<<"break"<<endl;
                break;
            }
        }
        if (node == nullptr && i < k)
        {
            now->next = cur;
            break;
        }

        while (!stk.empty())
        {
            now->next = stk.top();
            cout << "==" << stk.top()->val << endl;
            stk.pop();
            now = now->next;
        }
        //cout<<"======1"<<endl;
        cur = node;
    }
    return dummynode->next;
}

/*
½¨Á¢Á´±í
*/
ListNode* Creat_ListNode(vector<int>& a,int k)
{
    ListNode* head, * p1, * p2;
    p1 = p2 = head = new ListNode;
    head->next = NULL;
    for (size_t i = k; i > 0; i--)
    {
        p1 = new ListNode;
        p1->val = a[k-i];
        p1->next = NULL;
        if (head->next == NULL)
        {
            head->next = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    return head;
}


int main(void)
{
    vector<int> a = { 1,2,3,4,5,6 };
    ListNode* head = Creat_ListNode(a,a.size());

    reverseKGroup(head,2);

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

