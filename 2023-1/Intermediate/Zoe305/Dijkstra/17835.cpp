#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 0x7f7f7f7f7f7f;
const int MX = 100'002;
int n, m, k;
ll d[MX];
vector<pair<ll,int>> adj[MX];
priority_queue< pair<ll, int>,
                vector<pair<ll, int>>,
                greater<pair<ll, int>> > pq;

void solve(){
  while(!pq.empty()){
    int u, v;
    ll w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      dw += w;
      if(dw >= d[v]) continue;
      d[v] = dw;
      pq.push({dw, v});
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  fill(d + 1, d + n + 1, INF);

  int u, v;
  ll w;
  while(m--){
    cin >> u >> v >> w;
    adj[v].push_back({w, u});
  }

  int ct;
  while(k--){
    cin >> ct;
    d[ct] = 0;
    pq.push({d[ct], ct});
  }

  solve();

  int cidx = max_element(d + 1, d + n + 1) - d;
  cout << cidx << '\n' << d[cidx];
}