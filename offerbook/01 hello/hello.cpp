#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

#pragma pack(show)
#pragma message("���Զ���")     //�����ʱ����Կ���  Ctrl+F7

/*
1. ��C++�У�charռһ���ֽڣ�int/float/long��ռ4���ֽڣ�doubleռ8���ֽ� 
2. ����C++���е����ݶ��룬���ڶ���˳��Ĳ�ͬ���ǻ��в�һ��Ӱ���
3. �ڴ��������ѡ�ջ����������ȫ���������ȫ�ֱ�������̬�����Լ������ַ��������ݣ�

*/

class NULLL
{
public:
	
	int a;
	double b;
	char c;
	
/*
P22
һ���յ�������sizeof�Ľ���Ƕ���?
1
*/
};

class test
{
public:
	char a;
	int b;
	short c;
};

int main(void)
{
	test n;
	cout << sizeof(n) << endl;
	cout << sizeof(n.a) << endl;
	cout << sizeof(n.b) << endl;
	cout << sizeof(n.c) << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

