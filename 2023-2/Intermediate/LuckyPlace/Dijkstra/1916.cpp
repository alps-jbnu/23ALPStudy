#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define LL long long
#define W first
#define N second
using namespace std;

int n, m, a, b, c, s, e;
vector<pair<LL, LL>> adj[1002];
LL d[1002];
const LL INF = LLONG_MAX;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	cin >> s >> e;

	for (int i = 1; i <= n; i++)
		d[i] = INF;

	priority_queue <pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> pq;
	d[s] = 0;
	pq.push({ d[s], s });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		if (cur.W != d[cur.N])
			continue;
		for (auto nxt : adj[cur.N])
		{
			if (nxt.W + d[cur.N] < d[nxt.N])
			{
				d[nxt.N] = nxt.W + d[cur.N];
				pq.push({ d[nxt.N], nxt.N });
			}
		}
	}
	cout << d[e];

	return 0;
}
