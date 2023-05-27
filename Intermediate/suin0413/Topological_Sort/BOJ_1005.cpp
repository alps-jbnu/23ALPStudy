#include <bits/stdc++.h>
using namespace std;

int ans[1003], d[1003], deg[1003];
int t, n ,k, w;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    vector<int> adj[1003];
    cin >> n >> k;
    for(int i = 1;i<=n;i++) cin >> d[i];
    while(k--){
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      deg[y]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
  // 시간(작은 것부터), 번호
    for(int i = 1;i<=n;i++){
      if(deg[i] == 0) q.push({d[i], i});
    }
    while(!q.empty()){
      auto cur = q.top(); q.pop();
      ans[cur.second] = cur.first;
      for(auto nxt : adj[cur.second]){
        deg[nxt]--;
        if(deg[nxt] == 0) q.push({d[nxt]+cur.first,nxt});
      }
    }
    cin >> w;
    cout << ans[w] << "\n";
  }
}
