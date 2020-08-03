#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <map> 
#include <string> 

using namespace std;


int main(void)
{
	string s1 = "hello";
	map<int, string> My_map;
	My_map.insert(pair < int, string>(1,s1));

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

