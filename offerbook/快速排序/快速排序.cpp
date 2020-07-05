#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
�����������Ҫ˼�������㣺
1. ���������ѡȡһ������Ϊ��׼�㣬ͨ���Ƚ��ҳ����ֵ�������еĶ�λ
2. ������˼����еݹ����

ͨ���ݹ�Ĵ���Ҫ��ѭ���Ĵ������ܶ࣬��������ʵ�֣�������codingʱ
���Ծ���ѡ��ʹ�õݹ顣
�ݹ��ȱ�㣺
1. ���ĸ����ʱ��Ϳռ�
2. ���ܻᷢ������ջ���

����˵������Ŀ�����쳲��������е���ⷽʽ
*/

/*
*���ټ�һ���β�length��ʾ��������ĳ��ȣ�������������������
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
    QuickSort(a, 3, 6);

    for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%d  ", a[i]);
    }

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

