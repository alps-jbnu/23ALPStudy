#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,e,v1,v2;

vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;
int ans = 0;

int func(int st, int ed){
  int d[1005];
  fill(d,d+n+1,INF);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  d[st] = 0;
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop(); 
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      d[nxt.Y] = d[cur.Y]+nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }
  return d[ed];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);  
  cin >> n >> e;
  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a}); // 양방향 길
  }
  cin >> v1 >> v2; // v1 >v2이든 v2->v1이든 상관 X
  if(func(1, v1) == INF || func(v1, v2) == INF || func(v2, n) == INF) cout << "-1";
  else cout << min(func(1, v2)+func(v2, v1)+func(v1, n), func(1, v1)+func(v1, v2)+func(v2, n));
}
