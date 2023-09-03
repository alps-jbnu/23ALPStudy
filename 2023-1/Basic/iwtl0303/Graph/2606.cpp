#include <bits/stdc++.h>
using namespace std;

int v, e, a, b;
vector <int> adj[105];
int vis[105];
int ans = 0;

void dfs(int cur){
  vis[cur] = 1;
  for(auto nxt: adj[cur]){
    if(vis[nxt]) continue;
    ans++;
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;
  while(e--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);
  cout << ans;
}
