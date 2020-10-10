#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <map>
#include <hash_map>
#include <unordered_map>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


/*
检测环形入口，
思路：
第一次相遇时：f=2s;  f=s+nb;  =>  s=nb;  f=2nb;
相遇的点一定满足：f=a+nb
第二次时让f回到head节点，同时以一步的速度往前移动

这个题目不单考虑语言，还考察了数学思维

*/
ListNode* detectCycle(ListNode* head) {
	ListNode* fast, * slow;
	fast = slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)//判断是否有环
		{
			//第一次相遇时，s走了nb步，然后让回到头结点
			fast = head;
			while (fast==slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
	}
	return NULL;
}


/*
https://leetcode-cn.com/problems/linked-list-cycle/

思路：快慢指针，如果有环，两者最终一定相遇

*/

bool hasCycle(ListNode* head) {
	ListNode *fast, *slow;
	fast = slow = head;


	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}



/*
两数之和，使用hash_map的方法
*/
vector<int> twoSum(vector<int>& nums, int target) {
	int len = nums.size();
	vector<int> ret{0,0};
	hash_map<int, int> mymap;
	for (int i = 0; i < len; i++)
	{
		if (mymap.find(nums[i]) != mymap.end())
		{
			ret[0] = i;
			ret[1] = mymap.at(nums[i]);
			return ret;
		}
		mymap.insert(target - nums[i], i);
	}
	return ret;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

