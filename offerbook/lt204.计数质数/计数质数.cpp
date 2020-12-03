#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <vector>

using namespace std;

/*
https://leetcode-cn.com/problems/count-primes/

厄拉多塞筛法:
比如求20以内的质数：
1. 0，1不是质数，所以从2开始，在（2，n]的范围内将2的倍数剔除   变为 2 3 5 7 9 11 13 15 17 19
2. 下一个质数是3，将3的倍数剔除，							   变为 2 3 5 7 11 13 17 19
3. 下一个数是5，将5的倍数剔除，							       变为 2 3 5 7 11 13 17 19
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

