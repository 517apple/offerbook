#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

#pragma pack(show)
#pragma message("测试而已")     //编译的时候可以看到  Ctrl+F7

/*
1. 在C++中，char占一个字节，int/float/long都占4个字节，double占8个字节 
2. 关于C++类中的数据对齐，对于定义顺序的不同还是会有不一定影响的
3. 内存四区：堆、栈、代码区、全局区（存放全局变量、静态变量以及产量字符串等数据）

*/

class NULLL
{
public:
	
	int a;
	double b;
	char c;
	
/*
P22
一个空的类型求sizeof的结果是多少?
1
*/
};

int main(void)
{
	NULLL n;
	cout << sizeof(n) << endl;
	cout << &(n.a) << endl;
	cout << &(n.b) << endl;
	cout << &(n.c) << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

