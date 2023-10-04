#include<bits/stdc++.h>

using namespace std;

int arr[501][501];

int main(void)
{
	int n, i, j;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < i+1; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for(i = n-1; i >= 1; i--)
	{
		for(j = 0; j < i; j++)
		{
			arr[i-1][j] += max(arr[i][j], arr[i][j+1]);
		}
	}
	
	cout << arr[0][0];
	
	return 0;
}
