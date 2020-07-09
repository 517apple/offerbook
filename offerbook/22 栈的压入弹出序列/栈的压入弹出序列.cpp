#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>


using namespace std;



bool IspopOrder(const int* pPush,const int* pPop, int length)
{
	bool IsOrder = false;
	if (pPush != NULL || pPop != NULL || length > 0)
	{
		const int* ppush = pPush;
		const int* ppop = pPop;
		stack<int> s1;
		while (ppop-pPop!=length)
		{
			while (s1.empty() || s1.top() != *ppop)
			{
				s1.push(*ppush);
				ppush++;
				if (ppush - pPush >= length)
					break;
			}
			s1.pop();
			ppop++;
		}
		if(s1.empty() && ppop-pPop==length)
			IsOrder = true;

	}
	return IsOrder;
}

int main(void)
{
	const int a[5] = { 1,2,3,4,5 };
	const int b[5] = { 4,5,3,2,1 };

	int x = 1;

	while(x--)
		cout << IspopOrder(a,b,5) << endl;

	system("pause");
	return 0;

}

