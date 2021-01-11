#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <map> 
#include <string> 
#include <vector>
#include <unordered_map>

using namespace std;

class A {
public:
	A()
	{
		cout << "A 的构造函数...." << endl;
	}
	A(const A& a)
	{
		cout << "A 的拷贝构造函数...." << endl;
	}
	~A()
	{ 
		cout << "A 的析构函数...." << endl;
	}
};

void func()
{
	vector<A> arr;
	A a;
	cout << &a << endl;
	//arr.push_back(a);
	arr.emplace_back(a);
	cout << &arr[0] << endl;
}

int main(void)
{
	string s1 = "hello";
	map<int, string> My_map;
	My_map.emplace(pair < int, string>(1, s1));
	My_map.emplace(pair < int, string>(1, "apple"));
	//My_map[2].emplace_back("12");

	unordered_map<double, vector<vector<int>>> m;
	vector<int> vec;

	//func();

	unordered_map<int, int> mp;
	mp[1] = 2;
	//if (mp[2] == 1);
	cout << mp[2] << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

