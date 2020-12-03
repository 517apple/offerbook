#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <map>
#include <vector>

using namespace std;

/*
* 
https://leetcode-cn.com/problems/insertion-sort-list/


*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};


ListNode* head1;

void helper(ListNode* head, ListNode* node)
{
    if (node == nullptr)
        return;

    //首先遍历一遍将node的前后两个节点连接起来
    ListNode* preNode = head;
    ListNode* nextNode = node->next;
    while (preNode && preNode->next != node)
    {
        preNode = preNode->next;
    }
    preNode->next = node->next;

    ListNode* lastNode;
    lastNode = preNode = head;
    while (lastNode && (node->val > lastNode->val))
    {
        preNode = lastNode;
        lastNode = lastNode->next;
    }
    if (lastNode != preNode)
    {
        preNode->next = node;
        node->next = lastNode;
    }
    else
    {
        node->next = lastNode;
        head1 = node;
    }
    
    preNode = head1;
    while (preNode)
    {
        cout << preNode->val << "->";
        preNode = preNode->next;
    }
        
    cout << endl;

    helper(head1, nextNode);

}


ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    head1 = head;
    helper(head1, head->next);

    return head1;
}


ListNode* insertionSortList1(ListNode* head) {
    ListNode *dummy = new ListNode(0), *pre;
    dummy->next = head;

    while (head != nullptr && head->next != nullptr) {
        if (head->val <= head->next->val) {
            head = head->next;
            continue;
        }
        pre = dummy;

        while (pre->next->val < head->next->val) pre = pre->next;

        ListNode* curr = head->next;
        head->next = curr->next;
        curr->next = pre->next;
        pre->next = curr;
    }
    return dummy->next;
}



ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    map<int, vector<ListNode*>> mymap;
    while (head)
    {
        mymap[head->val].emplace_back(head);
        head = head->next;
    }

    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (auto iter = mymap.begin(); iter != mymap.end(); iter++)
    {
        vector<ListNode*> temp = iter->second;
        for (auto pnode : temp)
        {
            cur->next = pnode;
            cur = pnode;
        }
    }
    cur->next = nullptr;
    return dummy->next;
}


int main(void)
{
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
//    ListNode* node1 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    //insertionSortList(node1);
    ListNode* node = sortList(node1);
    while (node)
    {
        cout << node->val << "->";
        node = node->next;
    }
    cout << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

