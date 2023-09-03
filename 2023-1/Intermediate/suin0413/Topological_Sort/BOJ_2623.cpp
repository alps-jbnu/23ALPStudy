#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int deg[1001];
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    int c;
    cin >> c;
    for(int i = 0;i<c;i++){
      int a,b;
      cin >> b;
      if(i != 0) {
        adj[a].push_back(b);
        deg[b]++;
      }
      a = b;
    }
  }
  queue<int> q;
  queue<int> ans;
  for(int i = 1;i<=n;i++){
    if(deg[i] == 0) q.push(i);
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    ans.push(cur);
    for(auto nxt : adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }
  if(ans.size() != n){
    cout << "0";
    return 0;
  }
  while(!ans.empty()){
    cout << ans.front() << "\n"; ans.pop();
  }
}
