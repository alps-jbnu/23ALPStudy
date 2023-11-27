#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, u, v, d;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> d;
        adj[u].push_back({ v, d });
        adj[v].push_back({ u, d });
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        queue<pair<int, int>> q;
        vector<bool> vis(N + 1);
        q.push({ u, 0 });
        vis[u] = true;
        while (!q.empty()) {
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (cur == v) {
                cout << dist << '\n';
                break;
            }
            for (pair<int, int> nxt : adj[cur]) {
                if (vis[nxt.first]) continue;
                vis[nxt.first] = true;
                q.push({ nxt.first, dist + nxt.second });
            }
        }
    }
}
