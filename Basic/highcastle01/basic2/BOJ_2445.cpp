#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, j, k, l;
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			cout << "*";
		}
		for(k = 0; k < 2 * n - 2 * i; k++)
		{
			cout << " ";
		}
		for(l = 1; l <= i; l++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	for(i = n - 1; i > 0; i--)
	{
		for(j = 1; j <= i; j++)
		{
			cout << "*";
		}
		for(k = 0; k < 2 * n - 2 * i; k++)
		{
			cout << " ";
		}
		for(l = 1; l <= i; l++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
