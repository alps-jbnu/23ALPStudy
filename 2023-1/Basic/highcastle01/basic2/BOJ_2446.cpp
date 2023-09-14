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
		for(j = 0; j < i - 1; j++)
		{
			cout << " ";
		}
		for(k = 0; k < n - (i-1); k++)
		{
			cout << "*";
		}
		for(l = 0; l < n - i; l++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	for(i = 2; i <= n; i++)
	{
		for(j = 1; j <= n - i; j++)
		{
			cout << " ";
		}
		for(k = 1; k < 2 * i; k++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
