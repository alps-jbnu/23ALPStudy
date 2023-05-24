#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int deg[32005];
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    deg[b]++;
  }
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 1;i<=n;i++){
    if(deg[i] == 0) q.push(i);
  }
  while(!q.empty()){
    auto cur = q.top(); q.pop();
    cout << cur << " ";
    for(auto nxt : adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }
}
