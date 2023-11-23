#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101005];
int dist[101005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            adj[n + i].push_back(x); // n+i번 정점 : i번째 하이퍼튜브의 정점
            adj[x].push_back(n + i);
        }
    }
    fill(dist, dist + n + m + 1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    if (dist[n] == -1) cout << dist[n];
    else cout << dist[n] / 2 + 1;
}
