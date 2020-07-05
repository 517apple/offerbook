#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <time.h>

using namespace std;


/*
���õݹ�ķ�ʽ
50   12586269025  14......

*/
long long Fibonacci(size_t n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/*
������⼼��ѡ����ʺϵ�ѭ����ⷽʽ
*/
long long Fibonacci1(unsigned int n)
{
	int result[2] = { 0,1 };
	if (n < 2)
		return result[n];

	long long fib1 = 0, fib2 = 1,fibN=0;
	for (size_t i = 2; i <=n; i++)
	{
		fibN = fib1 + fib2;

		fib1 = fib2;
		fib2 = fibN;
	}

	return fibN;

}

int main(void)
{
	clock_t start_time, end_time;
	start_time = clock();   //��ȡ��ʼִ��ʱ��

	cout << Fibonacci(35) << endl;

	end_time = clock();     //��ȡ����ʱ�� 
	printf("%.1f ms\n", (double)(end_time - start_time));

	start_time = clock();   //��ȡ��ʼִ��ʱ��

	cout << Fibonacci1(35) << endl;

	end_time = clock();     //��ȡ����ʱ�� 
	printf("%.1f ms\n", (double)(end_time - start_time));

	system("pause");
	return 0;

}

