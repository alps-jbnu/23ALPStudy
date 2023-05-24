#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

vector<tuple<int, int, int>> e;
int p[MX + 2], ans;
int n, m;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

void solve(bool is_max_calc) {
  int sum = 0, cnt = 0;
  fill(p, p + MX + 2, -1);
  for(auto [cost, u, v] : e) {
    if(!is_diff_group(u, v)) continue;
    cnt++;
    sum += cost;
    if(cnt == n) break;
  }
  if(is_max_calc) ans += sum * sum;
  else ans -= sum * sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  m++;
  
  while(m--) {
    int u, v; bool cost;
    cin >> u >> v >> cost;
    e.push_back({!cost, u, v});
  }

  sort(e.begin(), e.end());
  solve(0);

  sort(e.rbegin(), e.rend());
  solve(1);

  cout << ans;
}