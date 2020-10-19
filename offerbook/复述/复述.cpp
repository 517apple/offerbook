#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>


using namespace std;



int main(void)
{
	char a[] = { 'a','b','\0' };
	char* beg = begin(a);
	char* last = end(a);
	size_t len = strlen(a);


	for (auto c : a)
		cout << c << endl;

	string s1 = "abc\ndef\nqwer";


	string s2;
	getline(cin, s2);

	cout << s2 << endl;
	system("pause");
	return 0;

}

