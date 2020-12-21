#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/

*/


/*
1. 只要确定前面两个数，后面的序列就已经确定了，只需要验证字符串中的数字是否满足要求即可


*/
vector<int> splitIntoFibonacci(string S) {
    vector<int> res;
    int len = S.size();
    if (len < 3)
        return res;

    //提取前面两个数,每个数的长度要小于等于字符串长度的一半
    for (int i = 1; i < len / 2; i++)//提取的第一个字符串的长度
    {
        int a = atoi(S.substr(0, i).c_str());
        
        for (int j = 1; j < len / 2; j++)//提取的第二个字符串的长度
        {
            int b = atoi(S.substr(i, j).c_str());
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);

            cout << a << ":" << b << endl;

            int index = i + j;
            long a1 = a, b1 = b;
            while (index < len)
            {
                long c = a1 + b1;
                string sc = to_string(c);
                if (index + sc.size() > len)
                    break;
                for (auto ch : sc)
                {
                    if (index < len && ch == S[index++])
                        continue;
                    break;
                }
                temp.push_back(c);
                a1 = b1;
                b1 = c;
            }
            if (index == len)
                return temp;
        }
    }

    return res;
}


int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

