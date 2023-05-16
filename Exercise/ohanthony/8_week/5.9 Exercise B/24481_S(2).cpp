#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int N, M, R;
int u, v;

vector<int> graph[100005];
int vis[100005];

void dfs(int st, int cnt) {
  vis[st] = cnt;
  for (int i = 0; i < graph[st].size(); i++) {
    if (vis[graph[st][i]] != -1) continue;
    dfs(graph[st][i], cnt + 1);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> R;
  while (M--) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // 오름차순 정렬
  for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

  memset(vis, -1, sizeof(vis));
  dfs(R, 0);

  for (int i = 1; i <= N; i++) cout << vis[i] << '\n';
  return 0;
}