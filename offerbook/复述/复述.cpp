#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <deque>
#include <vector>

using namespace std;

int reverse(int x) {
	unsigned int temp = 0;
	int res = x < 0 ? -1 : 1;
	temp = x * res;

	deque<int> q1;
	while (temp)
	{
		q1.push_back(temp % 10);
		temp /= 10;
	}
	if ((q1.size() >= 10) && (q1.front() > 2))
		return 0;
	while (!q1.empty())
	{
		temp = temp + q1.front() * (unsigned int)pow(10, q1.size() - 1);
		if ((temp >> 31) > 0)
			return 0;
		q1.pop_front();
	}

	
	
	return temp * res;
}

int main(void)
{
	//cout << reverse(1534236469) << endl;
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;

	vector<string> vs = {"flower", "flow", "flight"};
	cout << vs.size() << endl;
	string s1;
	vs[0].erase(2);
	cout << vs[0] << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

