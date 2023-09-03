#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[100001];
bool vis[100001];

void dfs(int cur){
  if(vis[cur]) return;
  vis[cur] = true;
  for(auto nxt : adj[cur])
    dfs(nxt);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  int groupcnt = 0;
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    dfs(i);
    groupcnt++;
  }
  cout << (groupcnt-1) + (m+groupcnt-1)-(n-1);
}
