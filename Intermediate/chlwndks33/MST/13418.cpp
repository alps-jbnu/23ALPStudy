#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

vector<tuple<int, int, int>> e;
int p[1002], ans;
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

void solve(bool chk) {
  int sum = 0, cnt = 0;
  fill(p, p + 1002, -1);
  for(auto [cost, u, v] : e) {
    if(!is_diff_group(u, v)) continue;
    cnt++;
    sum += cost;
    if(cnt == n) break;
  }
  if(chk) ans += sum * sum;
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