#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
const int MAX = 50000 + 1;
using namespace std;

int N, M;
int arr[MAX], DP[4][MAX];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int x; cin >> x;

		arr[i] = arr[i - 1] + x;
	}

	cin >> M;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i * M; j <= N; j++)
		{
			DP[i][j] = max(DP[i][j - 1], DP[i - 1][j - M] + arr[j] - arr[j - M]);
		}
	}
	cout << DP[3][N];

	return 0;
}