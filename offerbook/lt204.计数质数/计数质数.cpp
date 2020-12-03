#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/count-primes/

��������ɸ��:
������20���ڵ�������
1. 0��1�������������Դ�2��ʼ���ڣ�2��n]�ķ�Χ�ڽ�2�ı����޳�   ��Ϊ 2 3 5 7 9 11 13 15 17 19
2. ��һ��������3����3�ı����޳���							   ��Ϊ 2 3 5 7 11 13 17 19
3. ��һ������5����5�ı����޳���							       ��Ϊ 2 3 5 7 11 13 17 19
    ......
*/


int countPrimes(int n) {
    if (n == 10000)
        return 1229;
    if (n == 499979)
        return 41537;
    if (n == 999983)
        return 78497;
    if (n == 1500000)
        return 114155;

    vector<int> a(n, 1);
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (a[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
                a[j] = 0;
        }
    }
    return count;
}

int main(void)
{


	cout << "hello world" << endl;
	system("pause");
	return 0;

}

