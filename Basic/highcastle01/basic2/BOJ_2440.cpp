#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, j, k;
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n - i + 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
