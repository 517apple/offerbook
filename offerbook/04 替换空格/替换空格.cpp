#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 

using namespace std;

void ReplaceBlack(char string[], int length)
{
	if (string == NULL || length <= 0)
		return;
	int oldlen=0, spacenum=0,i=0;
	while (string[i]!='\0')
	{
		oldlen++;
		if (string[i] == ' ')
			spacenum++;

		++i;
	}
	int newlen = oldlen + 2 * spacenum;
	if (newlen > length)
		return;
	int oldindex, newindex;
	oldindex = oldlen;
	newindex = newlen;
//	while(oldindex!= newindex)
	while(oldindex>=0 && newindex>oldindex)
		if (string[oldindex] == ' ')
		{
			oldindex--;
			string[newindex--] = '0';
			string[newindex--] = '2';
			string[newindex--] = '%';
		}
		else
		{
			string[newindex--] = string[oldindex--];
		}
}

int main(void)
{
	char *s1 = new char[100];
	char s2[20]="xdfsff";

	cout << s2 << endl;

	ReplaceBlack(s2, 20);

	cout << s2 << endl;

	cout << "hello world" << endl;
	system("pause");
	return 0;

}

