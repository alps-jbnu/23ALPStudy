#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}
