#include <bits/stdc++.h>
const int MAX = 100000 + 1;
using namespace std;

int N, M, temp = 0;
int arr[MAX];
int DP[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	while (M--)
	{
		int x, y, z; cin >> x >> y >> z;
		DP[x] += z;
		DP[y + 1] -= z;
	}

	for (int i = 1; i <= N; i++)
	{
		temp += DP[i];
		arr[i] += temp;

		cout << arr[i] << " ";
	}

	return 0;
}