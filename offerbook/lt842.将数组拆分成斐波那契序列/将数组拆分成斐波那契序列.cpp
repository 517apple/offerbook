#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/

*/


/*
1. ֻҪȷ��ǰ������������������о��Ѿ�ȷ���ˣ�ֻ��Ҫ��֤�ַ����е������Ƿ�����Ҫ�󼴿�


*/
vector<int> splitIntoFibonacci(string S) {
    vector<int> res;
    int len = S.size();
    if (len < 3)
        return res;

    //��ȡǰ��������,ÿ�����ĳ���ҪС�ڵ����ַ������ȵ�һ��
    for (int i = 1; i < len / 2; i++)//��ȡ�ĵ�һ���ַ����ĳ���
    {
        int a = atoi(S.substr(0, i).c_str());
        
        for (int j = 1; j < len / 2; j++)//��ȡ�ĵڶ����ַ����ĳ���
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

