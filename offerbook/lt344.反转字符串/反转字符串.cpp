#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>


using namespace std;

/*
https://leetcode-cn.com/problems/reverse-string/


*/


void reverseString(vector<char>& s) {
	int len = s.size();

	for (int i = 0; i < len / 2; i++)
		swap(s.at(i), s.at(len - i));
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

