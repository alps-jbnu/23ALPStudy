#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int m[100];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m[i];

	}

	int x;

	cin >> x;

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (m[i] == x)
			cnt++;


	}

	cout << cnt;



}
