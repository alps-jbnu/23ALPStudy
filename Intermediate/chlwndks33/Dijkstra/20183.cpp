#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define X first
#define Y second
#define ll long long

ll n,m,st,en;
ll won;
ll l=1;
ll hi;

//{비용, 정점번호}
vector<pair<ll,ll>> adj[500001];
const int INF = 0x7f7f7f7f;
ll d[100001];

//1. 경로 비용 중 최댓값이 mid 이하
//2. 가진 비용으로 갈 수 있어야 한다.
bool solve(ll lim) {
  priority_queue < pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>> > pq;
  memset(d, 0x3f, sizeof(d));
  d[st] = 0;
  pq.push({0, st});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]) {
      if(nxt.X > lim) continue;
      nxt.X += cur.X;
      if(d[nxt.Y] <= nxt.X) continue;
      d[nxt.Y] = nxt.X;
      pq.push({nxt.X, nxt.Y});
    }
  }
  if(d[en] > won) return 0;
  return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> st >> en >> won;
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        hi = max(hi,w);
    }
    while(l < hi) {
        ll mid = (l + hi) / 2;
        if(solve(mid)) hi = mid;
        else l = mid + 1;
    }

    if(solve(l)) cout << l;
    else cout << -1;
}