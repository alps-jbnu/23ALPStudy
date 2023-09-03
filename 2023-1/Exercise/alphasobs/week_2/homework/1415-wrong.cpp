#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
const int MAX = 10000 + 1;
const int INF = 500000 + 1;
using namespace std;

ll N, ans = 0;
int arr[MAX];
ll DP[INF];
bool IsTrue[INF];
vector<int> vec;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	IsTrue[0] = IsTrue[1] = 1;
	for (int i = 2; i < 707; i++)
	{
		if (IsTrue[i]) continue;
		for (int j = i * i; j < 500001; j += i) IsTrue[j] = 1;
	}

	DP[0] = 1;

	cin >> N;
	while (N--)
	{
		int p; cin >> p;
		arr[p]++;
	}

	for (int i = 10000; i > 0; i--)
	{
		int temp = 0;
		int cnt = arr[i];

		while (cnt--)
		{
			temp += i;
			vec.push_back(temp);
		}

		if (vec.empty()) continue;

		for (int j = 500000; j > 0; j--)
		{
			for (auto x : vec)
			{
				if (j - x < 0) break;
				DP[j] += DP[j - x];
			}
		}
	}


	for (int i = 2; i < 500000; i++)
	{
		if (IsTrue[i]) continue;
		ans += DP[i];
	}

	cout << ans * (arr[0] + 1);
}