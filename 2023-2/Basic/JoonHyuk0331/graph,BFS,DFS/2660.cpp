#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51];
int max_dist[51];
int n;

void bfs() {
   for (int i = 1; i <= n; i++) {
        int vis[51] = { 0, };
        int dist[51] = { 0, };
        queue<int> q;

        q.push(i);
        vis[i] = true;
        dist[i] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
                dist[nxt] = dist[cur] + 1;
                if (max_dist[nxt] < dist[nxt])//정점nxt과 현재 기준 정점의 거리가 기존 다른 정점들과의 거리보다 클 경우 새로 갱신
                    max_dist[nxt] = dist[nxt];
            }
        }
    }
}

int main() {
    int min = 0;
    vector<int> candidate;
    cin >> n;//정점의 개수(인원)를 입력받는다
    while (true) {
        int v, e;
        cin >> v >> e;
        if (v == EOF)
            break;
        adj[v].push_back(e);
        adj[e].push_back(v);
    }

    bfs();

    min = max_dist[1];
    for (int i = 1; i <= n; i++)
        if (min > max_dist[i])
            min = max_dist[i];

    for (int i = 1; i <= n ; i++) {
        if (max_dist[i] == min) {
            candidate.push_back(i);
        }
    }

    cout << min <<' '<< candidate.size() << '\n';
    for (auto it = candidate.begin(); it != candidate.end(); ++it) {
        cout << *it << " "; 
    }
}
