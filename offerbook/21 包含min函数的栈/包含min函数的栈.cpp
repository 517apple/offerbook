#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stack>

using namespace std;


template <class	T>
class StackWithMin {
public:
	void push(const T& value);
	void pop();
	const T& min();

private:
	stack<T> m_data, m_min;
};

template <class T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template<class T>
void StackWithMin<T>::pop()
{
	if (m_data.size() == 0 || m_min.size() == 0)
		return;
	m_data.pop();
	m_min.pop();
}

template<class T>
const T& StackWithMin<T>::min()
{
	return m_min.top();
	// TODO: 在此处插入 return 语句
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}


