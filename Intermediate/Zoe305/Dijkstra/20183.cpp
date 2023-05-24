#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int NMX = 100000;
const int MMX = 500000;
vector<pair<ll, int>> adj[MMX + 2];
ll dist[NMX + 2];

ll lo = 1, hi;
int n, m, st, en; ll c;

bool solve(ll lim) {
  priority_queue < pair<ll, int>,
      vector<pair<ll, int>>,
      greater<pair<ll, int>> > pq;

  memset(dist, 0x3f, sizeof(dist));

  dist[st] = 0;
  pq.push({0, st});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(dist[cur] != co) continue;
    for(auto [d, nxt] : adj[cur]){
      if(d > lim) continue;
      d += co;
      if(dist[nxt] <= d) continue;
      dist[nxt] = d;
      pq.push({d, nxt});
    }
  }

  if(dist[en] > c) return 0;
  return 1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st >> en >> c;

  while(m--){
    int u, v; ll cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
    hi = max(hi, cost);
  }

  while(lo < hi){
    ll mid = (lo + hi) / 2;
    if(solve(mid)) hi = mid;
    else lo = mid + 1;
  }

  if(solve(lo)) cout << lo;
  else cout << -1;
}