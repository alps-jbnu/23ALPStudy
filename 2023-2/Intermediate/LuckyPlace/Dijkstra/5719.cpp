#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define W first
#define N second
using namespace std;

const int INF = INT_MAX;
int d[502];
vector<int> pre[502];
bool vis[502];
vector<pair<int, int>> adj[502];
int n, m, s, e, u, v, p;

int dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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
				pre[nxt.N].clear();				// 최소값이 갱신 된 경우 clear
				d[nxt.N] = nxt.W + d[cur.N];
				pq.push({ d[nxt.N], nxt.N });
				pre[nxt.N].push_back(cur.N);
			}
			else if (nxt.W + d[cur.N] == d[nxt.N])		// 거리가 최소 다른 경로도 저장해야 하므로 추가
			{
				pre[nxt.N].push_back(cur.N);
			}
		}
	}
	return d[e];		// 도착지점의 거리 리턴
}

void remove_shortest()
{
	queue<int> q;
	q.push(e);
	vis[e] = true;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int previous : pre[cur])			
		{
			for (auto& node : adj[previous])
			{
				if (cur == node.N)
					node.N = -1;
				if (vis[previous])
					continue;
				q.push(previous);
				vis[previous] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		cin >> n >> m >> s >> e;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i <= n; i++)
		{
			// 초기화
			adj[i].clear();
			pre[i].clear();
			vis[i] = false;
			d[i] = INF;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> p;
			adj[u].push_back({ p, v });
		}
		dijkstra();
		remove_shortest();
		fill(d, d + n, INF);
		int ans = dijkstra();
		//cout << ans << "\n";
		if (ans == INF)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}

	return 0;
}
