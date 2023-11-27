#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define W first
#define N second
using namespace std;

vector<pair<int, int>> adj[100005];
bool chk[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
	chk[1] = true;
	for (auto nxt : adj[1])
		pq.push({ nxt.W, 1, nxt.N });
	int cnt = 0;
	int ans = 0;
	int max = 0;
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
		max = std::max(max, cost);
		for (auto nxt : adj[b])
			if (!chk[nxt.N])
				pq.push({ nxt.W, b, nxt.N });
	}
	cout << ans - max;
	return 0;
}
