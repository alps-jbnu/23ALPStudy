#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool isFriend;
int n, m, u, v;
vector<vector<int>> f(2005);

void dfs(int cnt, int dir, vector<vector<int>> &ff, vector<bool> &isVis) {
  if (cnt == 4) {
    isFriend = true;
    return;
  }

  for (int i = 0; i < ff[dir].size(); i++) {
    int nxt = ff[dir][i];
    if (isVis[nxt]) continue;
    isVis[nxt] = true;
    dfs(cnt + 1, nxt, ff, isVis);
    isVis[nxt] = false;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  cin >> n >> m;
  while (m--) {
    cin >> u >> v;
    f[u].push_back(v);
    f[v].push_back(u);
  }

  for (int i = 0; i < n; i++) {
    vector<bool> vis(n);
    vis[i] = true;
    dfs(0, i, f, vis);
    if (isFriend) {
      cout << isFriend;
      return 0;
    }
  }

  cout << isFriend;

  return 0;
}