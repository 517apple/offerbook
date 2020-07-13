#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
快速排序的主要思想有两点：
1. 随机或主动选取一个点作为基准点，通过比较找出这个值在数组中的定位
2. 将上述思想进行递归迭代

通常递归的代码要比循环的代码简简洁很多，更加容易实现，所以在coding时
可以尽量选择使用递归。
递归的缺点：
1. 消耗更多的时间和空间
2. 可能会发生调用栈溢出

最能说明这个的可能是斐波那契数列的求解方式
*/

/*
*可再加一个形参length表示整个数组的长度，参数检验避免数组溢出
*
*/
int Partition(int data[], int start, int end)
{
    if (data == NULL || start<0)
        return -1;
    int index = (start + end) / 2;
    swap(data[index], data[end]);
    index = start - 1;
    for (int i = start; i < end; i++)
    {
        if (data[i] < data[end])
        {
            index++;
            if (i != index)
                swap(data[i], data[index]);
        }
    }
    index++;
    swap(data[index], data[end]);

    return index;
}

void QuickSort(int data[], int start, int end)
{
    if (start == end)
        return;

    int index=Partition(data, start, end);

    if (index > start)
        QuickSort(data, start, index - 1);
    if (index < end)
        QuickSort(data, index + 1, end);

}

int main(void)
{

	int a[7] = {1,2,7,5,9,2,8};
    QuickSort(a, 0, 6);

    for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%d  ", a[i]);
    }

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

