#include <bits/stdc++.h>
using namespace std;

int n,m,u,v,tc,trees;
vector<int> adj[510];
bool vis[510], isTree;

void dfs(int cur, int prev){
  for(int nxt : adj[cur]){
    if(nxt == prev) continue;
    if (vis[nxt]){
      isTree = 0;
      continue;
    }
    vis[nxt] = 1;
    dfs(nxt,cur);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> n >> m;
    if(!n && !m) break;

    fill(vis, vis + n + 1, 0);
    for (int i = 1; i <= n; i++)
      adj[i].clear();
    trees = 0;

    while (m--) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      vis[i] = true;
      isTree = true;
      dfs(i, -1);
      trees += isTree;
    }
    cout << "Case " << ++tc << ": ";
    if (!trees)
      cout << "No trees." << '\n';
    else if (trees == 1)
      cout << "There is one tree." << '\n';
    else
      cout << "A forest of " << trees << " trees." << '\n';
  }
}
