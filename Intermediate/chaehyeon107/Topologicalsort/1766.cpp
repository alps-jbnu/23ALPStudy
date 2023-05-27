#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32002];
priority_queue< int, vector<int>, greater<int> > q;
int deg[32002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;

    while (m--) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        auto cur = q.top(); q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (!deg[nxt]) q.push(nxt);
        }
    }
}
