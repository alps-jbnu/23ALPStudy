#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1001];
int N, M, u, v, d;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
  }

  while (M--) {
    cin >> u >> v;
    queue<pair<int, int>> q;
    vector<bool> vis(N + 1);
    q.push({u, 0});
    vis[u] = true;

    while (!q.empty()) {
      auto [cur, dist] = q.front();
      q.pop();
      if (cur == v) {
        cout << dist << '\n';
        break;
      }
      for (auto [nxt, nxtDist] : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        q.push({nxt, dist + nxtDist});
      }
    }
  }
}