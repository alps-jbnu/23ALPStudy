#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

#define X first
#define Y second

int n, m;
int p[1002];
pair<int, int> v[1002];
vector< tuple<double, int, int> > e;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_parent(int a, int b) {
  a = find(a); b = find(b);
  if(a == b) return 0;
  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(p, p + n + 1, -1);
  
  int x, y;
  for(int i = 1; i <= n; i++) {
    cin >> x >> y;
    v[i] = {x, y};
  }
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    cin >> x >> y;
    if(is_diff_parent(x, y))
      cnt++;
  }

  long long len;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      int dx = (v[i].X - v[j].X);
      int dy = (v[i].Y - v[j].Y);
      len = ((long long)dx) * dx + ((long long)dy) * dy;
      e.push_back({len, i, j});
    }
  }

  sort(e.begin(), e.end());

  double ans = 0;
  for(auto cur : e) {
    tie(len, x, y) = cur;
    if(!is_diff_parent(x, y)) continue;
    ans += sqrt(len);
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << fixed;
  cout.precision(2);
  cout << ans;
}