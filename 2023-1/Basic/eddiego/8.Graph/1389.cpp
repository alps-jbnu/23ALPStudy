#include <bits/stdc++.h>
using namespace std;

const int MX = 100;
const int INF = 0x7f7f7f7f;

vector<int> adj[MX + 2];
int dist[MX + 2];

int mn = INF, ans;

int bfs(int st) {
    queue<int> q;
    int sum = 0;
    dist[st] = 0;
    q.push(st);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            sum += dist[nxt];
            q.push(nxt);
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        fill(dist, dist+n+1, -1);
        int sum = bfs(i);
        if(sum >= mn) continue;
        mn = sum;
        ans = i;
    }
    cout << ans;
}
/*
BFS를 활용한 풀이입니다.
모든 노드를 기점으로 BFS를 수행하면서 케빈베이컨 수를 구합니다(43-49번째 줄).
가중치가 1인 그래프이므로 BFS를 통해 각 노드까지 최단 거리로 도달할 수 있습니다.
노드 방문 시 그 노드까지 거리가 결정되므로,
구한 거리를 더하면서 sum을 갱신합니다(25번째 줄)

 #include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  int u, v;
  while(m--) {
    cin >> u >> v;
    d[u][v] = 1;
    d[v][u] = 1;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int ans, sum;
  int min = INF;
  for(int i = 1; i <= n; i++) {
    sum = 0;
    for(int j = 1; j <= n; j++)
      sum += d[i][j];
    if(sum < min) {
      min = sum;
      ans = i;
    }
  }
  cout << ans;
}

플로이드-워셜 알고리즘을 활용한 풀이입니다.
간선 정보를 받아 u-v, v-u로 가는 경로의 길이가 1이라고 설정합니다.
자기 자신으로 향하는 경로의 길이는 0으로 설정합니다.
그외 모든 경로는 INF로 초기화하고 시작합니다.
플로이드-워셜 알고리즘(28-31번째 줄)을 통해
임의의 노드 i에서 j로 향하는 최단 거리를 2차원 배열 d에 계산합니다.
이후 한 노드 i에서 다른 노드 j로 향하는 모든 경로를 더한 값을 sum에 할당한 뒤
최솟값과 비교합니다. 최솟값보다 작을 경우 sum을 갱신하고, 답을 i 노드로 갱신합니다.
*/