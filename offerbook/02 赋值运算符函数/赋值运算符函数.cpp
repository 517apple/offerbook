#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 


#pragma comment(lib,"Ws2_32.lib")


using namespace std;


/*
请为下面的CMyString类型添加赋值运算符函数
*/

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	CMyString& operator =(const CMyString& str)
	{
		if (this == &str)
			return *this;

		delete[]m_pData;
		m_pData = NULL;
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);

		return *this;
	}

//	~CMyString(void);

	void print()
	{
		cout << m_pData << endl;
	}
private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
{
	m_pData = pData;
}

//操作符= 重载
//CMyString& CMyString::operator *(const CMyString& str)



int main(void)
{
	char sp[] = "luo";
	CMyString s1(sp),s2(s1);

	s2.print();

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

