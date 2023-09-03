#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[10005];
bool chk[10005];
int board[305][305];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int a = 1; a <= n; a++) {
		int c, b = n + 1;
		cin >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			int c;
			cin >> c;
			if (!c) continue;
			adj[a].push_back({ c, b });
		}
	}

	int cnt = 0;
	int ans = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
					greater<tuple<int, int, int>>> pq;

	chk[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.X, 1, nxt.Y });
		
	// 어차피 물을 하나는 대야하므로 다른 조건 필요 X
	while (cnt < n) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b]) continue;
		chk[b] = 1;
		cnt++;
		ans += cost;
		for (auto nxt : adj[b]) {
			if (!chk[nxt.Y]) pq.push({ nxt.X, b, nxt.Y });
		}
	}

	cout << ans << '\n';

	return 0;
}
