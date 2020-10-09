#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <map>
#include <hash_map>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


/*
https://leetcode-cn.com/problems/linked-list-cycle/

˼·������ָ�룬����л�����������һ������

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
����֮�ͣ�ʹ��hash_map�ķ���
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

