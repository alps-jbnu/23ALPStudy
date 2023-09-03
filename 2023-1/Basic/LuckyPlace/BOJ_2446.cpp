#include <iostream>
using namespace std;

int main(void)
{
	int num;
	cin >> num;
	int starnum = (num * 2) - 1;
	int count = 0;
	for (int i = starnum; i >= 1; i = i - 2)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
		if (i == 1)
			break;
		for (int k = 0; k <= count; k++)
			cout << " ";
		count++;
	}
	count -= 1;
	for (int i = 3; i <= starnum; i = i + 2)
	{
		for (int k = 0; k < count; k++)
			cout << " ";
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
		count--;
	}
	return 0;
}