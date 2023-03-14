#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, j, k;
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			cout << " ";
		}
		for(k = 0; k < n - i; k++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
