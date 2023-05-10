#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,m,x;

vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;
int ans = 0;
int t[1005];

int func(int st, int ed){
  int d[1005];
  fill(d,d+n+1,INF);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  d[st] = 0;
  // 우선순위 큐에 (0, 시작점) 추가
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}    
    // 거리가 d에 있는 값과 다를 경우 넘어감
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      // cur를 거쳐가는 것이 더 작은 값을 가질 경우
      // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
      d[nxt.Y] = d[cur.Y]+nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }
  return d[ed];
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);  
  cin >> n >> m >> x;
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
  }

  for(int i = 1;i<=n;i++){
    t[i] += func(x, i) + func(i, x);
    ans = max(t[i], ans);
  }
  cout << ans;
}
