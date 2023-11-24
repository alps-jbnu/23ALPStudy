#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define W first
#define N second
using namespace std;

vector<pair<int, int>> adj[305];
bool chk[305];
int board[305][305];
int well[305];
int v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v;
	cin >> v;
	for (int i = 1; i <= v; i++)
		cin >> well[i];
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			cin >> board[i][j];
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j)
				continue;
			adj[i].push_back({ board[i][j], j });
		}
	}
	for (int i = 1; i <= v; i++)
	{
		adj[0].push_back({ well[i], i });
		adj[i].push_back({ well[i], 0 });
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	for (auto nxt : adj[1])
		pq.push({ nxt.W, 1, nxt.N });
	chk[1] = true;
	int cnt = 0;
	int ans = 0;
	while (cnt < v)
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
