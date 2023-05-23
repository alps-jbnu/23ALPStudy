#include <bits/stdc++.h>
using namespace std;

int p[1002];
int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

vector< tuple<int, int, int> > edge;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  fill(p, p + n, -1);

  int c;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> c;
      if(i == j) continue;
      edge.push_back({c, i, j});
    }

  sort(edge.begin(), edge.end());
  
  int u, v;
  int cnt = 0;
  long long ans = 0;
  for(auto edge : edge) {
    tie(c, u, v) = edge;
    if(!merge(u, v)) continue;
    ans += c;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << ans;
}