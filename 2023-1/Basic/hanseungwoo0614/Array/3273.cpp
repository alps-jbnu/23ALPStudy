#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int m[10000000];
	int z[10000000];


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
		z[m[i]] = 1;
	}

	int x;

	cin >> x;

	int cnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (z[x - m[i]] == 1 && x - m[i] >= 0)
			cnt++;
		else
			continue;

	}



	cout << cnt/2;


}
