#include <bits/stdc++.h>
using namespace std;
//못 품
int n, m;
vector<int> hv[101], li[101];
bool vis[101];

bool solve(int st, vector<int> (&adj)[]) {
  fill(vis, vis + n + 1, 0);
  queue<int> q;

  q.push(st);
  vis[st] = 1;

  int cnt = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = 1;
      cnt++;
    }
  }
  return cnt >= (n + 1)/2;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    hv[u].push_back(v);
    li[v].push_back(u);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans += (solve(i, hv) || solve(i, li));
  cout << ans;
}
