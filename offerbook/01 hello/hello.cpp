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

