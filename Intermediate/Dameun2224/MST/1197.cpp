#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];
int cnt = 0, result = 0;
// { 비용,출발점,도착점 }
priority_queue<tuple<int, int, int>, vector< tuple<int, int, int>>, greater< tuple<int, int, int>>> pq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}

	chk[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.X, 1, nxt.Y });
	
	while (cnt < v - 1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b]) continue;
		chk[b] = 1;
		result += cost;
		cnt++;
		for (auto nxt : adj[b]) pq.push({ nxt.X, b, nxt.Y });
	}

	cout << result << '\n';

	return 0;
}
