#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
int deg[10005];
int t[10005];
int n, m, ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1;i<=n;i++){
    cin >> t[i] >> m;
    while(m--){
      int a;
      cin >> a;
      adj[a].push_back(i);
      deg[i]++;
    }
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
  // 시간(작은 것부터), 번호
  for(int i = 1;i<=n;i++){
    if(deg[i] == 0) q.push({t[i], i});
  }
  while(!q.empty()){
    auto cur = q.top(); q.pop();
    ans = max(ans, cur.first);
    for(auto nxt : adj[cur.second]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push({t[nxt]+cur.first,nxt});
    }
  }
  cout << ans;
}
