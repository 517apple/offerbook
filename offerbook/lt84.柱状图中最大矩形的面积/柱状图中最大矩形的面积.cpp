#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <stack>

using namespace std;


/*
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/comments/
*/


int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> stk;
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!stk.empty() && heights[i] < heights[stk.top()])
        {
            int top = stk.top();
            cout << stk.top() << endl;
            stk.pop();
            maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
        }
        stk.push(i);

    }
    return maxArea;
}

int main(void)
{
    vector<int> a = { 2, 1, 5, 6, 2, 3 };
    largestRectangleArea(a);


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

