#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, u, v;
bool b;
int d[252][252];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  while(m--){
    cin >> u >> v >> b;
    d[u][v] = 0;
    d[v][u] = !b;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

  cin >> m;
  while(m--){
    cin >> u >> v;
    cout << d[u][v] << '\n';
  }
}