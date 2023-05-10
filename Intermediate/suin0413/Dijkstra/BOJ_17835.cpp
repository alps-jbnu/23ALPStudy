#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;

vector<pair<ll,ll>> adj[100005];
const ll INF = 1e+15;
ll d[100005];
ll ed[100005]; // 면접장
ll n,m,k;
pair<ll,ll> mx;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);  
  cin >> n >> m >> k;
  fill(d,d+n+1,INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[b].push_back({c,a}); // 그래프 역으로 저장
  }
  for(int i = 1;i<=k;i++) cin >> ed[i];
  
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
  for(int i = 1;i<=k;i++){
    int st = ed[i];
    d[st] = 0;
    pq.push({d[st], st});
  }
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(cur.X != d[cur.Y]) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      // 돌아가는 게 더 짧은 경우
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }

  for(int i = 1;i<=n;i++) {
    if(d[i]>mx.Y){
      mx.X = i;
      mx.Y = d[i];
    }
  }
  cout << mx.X << "\n" << mx.Y;

  // 역 그래프를 이용해 면접장 -> 각 지점
  // 시작점 모두 큐에 넣음!!
}
