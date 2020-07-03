#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;


/*
��Ϊ�����CMyString������Ӹ�ֵ���������
*/

class CMyString
{

	
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);

	CMyString& operator=(const CMyString& str);


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

//������= ����
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;

	delete[]m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}


int main(void)
{
	char sp[] = "luo";
	CMyString s1(sp),s2;
	s2 = s1;
	s1 = s1;

	s2.print();

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

