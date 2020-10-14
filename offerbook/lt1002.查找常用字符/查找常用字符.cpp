#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <string>

using namespace std;

vector<string> commonChars(vector<string>& A) {
	vector<int> res(26, 0);
	vector<string> ans;
 	for (char c : A[0])
		res[c - 'a']++;
	for (int i = 1; i < A.size(); i++)
	{
		vector<int> temp(26, 0);
		for (char c : A[i])
			temp[c - 'a']++;

		for (int j = 0; j < 26; j++)
			res[j] = min(res[j], temp[j]);
	}
	for (int j = 0; j < 26; j++)
		while (res[j]--)
		{
			//ans.push_back(to_string(char('a' + j)));
			string s = "";
			s += (j + 'a');
			ans.push_back(s);
		}

	return ans;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

