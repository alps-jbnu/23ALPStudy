#include <bits/stdc++.h>
using namespace std;

int n, m; 

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int ind[n + 2] = {};
  vector<int> adj[n + 2];
  priority_queue< int,
      vector<int>,
      greater<int> > pq;

  while(m--){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    ind[v]++;
  }
  for(int i = 1; i <= n; i++)
    if(!ind[i]) pq.push(i);

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    cout << cur << ' ';
    for(int nxt : adj[cur]){
      ind[nxt]--;
      if(!ind[nxt]) pq.push(nxt);
    }
  }
}