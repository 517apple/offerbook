#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>

using namespace std;


template <typename T> class CQueue
{
public:
	//CQueue(void);
	//~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;//‘≠ º’ª
	stack<T> stack2;//∑¥–Ú’ª
};


template <typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
	T node=NULL;
	if (stack2.empty())
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	
	if (stack2.empty())
		throw exception("the queue is empty!");

	node = stack2.top();
	stack2.pop();
	
	return node;
}



int main(void)
{
	CQueue<int> q1;
	for (size_t i = 0; i < 10; i++)
	{
		q1.appendTail(i);
	}
	q1.deleteHead();
	q1.appendTail(23);
	q1.deleteHead();


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

