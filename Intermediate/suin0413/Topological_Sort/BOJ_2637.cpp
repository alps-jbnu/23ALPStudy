#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[103];
int deg[103], cnt[103]; // indegree
int n, m;
bool isbase[103];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(isbase, isbase + n + 1, 1);
  while(m--){
    int x,y,k;
    cin >> x >> y >> k;
    isbase[x] = 0;
    adj[x].push_back({y, k});
    deg[y]++;
  }
  queue<int> q;
  q.push(n);
  cnt[n] = 1;

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(auto [nxt, c] : adj[cur]) {
      cnt[nxt] += c * cnt[cur];
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }

  for(int i = 1; i <= n; i++)
    if(isbase[i]) cout << i << ' ' << cnt[i] << '\n';  
}
