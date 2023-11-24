#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define W first
#define N second
#define LL long long
using namespace std;

vector<pair<int, int>> adj[1005];
bool chk[1005];
int board[1005][1005];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			adj[i].push_back({ board[i][j], j });
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for (auto nxt : adj[1])
		pq.push({ nxt.W, 1, nxt.N });
	chk[1] = true;
	int cnt = 0;
	LL ans = 0;
	while (cnt < n - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b])
			continue;
		chk[b] = true;
		cnt++;
		ans += cost;
		for (auto nxt : adj[b])
			if (!chk[nxt.N])
				pq.push({ nxt.W, b, nxt.N });
	}
	cout << ans;
	return 0;
}
