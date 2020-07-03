#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

/*
while 后面可以接一个包括if框架的整个语句
*/

bool Find(int* matrix, int rows, int columns, int number)
{
	int row, column;
	if ((matrix != NULL) && (rows > 0) && (columns > 0))
	{
		row = 0;
		column = columns - 1;
		while((column>=0)&&(row<rows))
		if (matrix[row * columns + column] == number)
			return true;
		else if (matrix[row * columns + column] > number)
			column--;
		else
			row++;
	}

}

int main(void)
{
	int a = 0;
	while (a < 100)
		if (a % 2 == 0)
			a++;
		else {
			++a;
			cout << "hello world" << endl;
		}

	cout << "hello world" << endl;

	system("pause");
	return 0;

}

