#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int v, e;
int d[402][402];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> v >> e;
  for(int i = 1; i <= v; i++){
    fill(d[i] + 1, d[i] + v + 1, INF);
    d[i][i] = 0;
  }

  int a, b, c;
  while(e--){
    cin >> a >> b >> c;
    d[a][b] = c;
  }

  for(int k = 1; k <= v; k++)
    for(int i = 1; i <= v; i++)
      for(int j = 1; j <= v; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int ans = INF;
  for(int i = 1; i <= v; i++)
    for(int j = i + 1; j <= v; j++)
      ans = min(ans, d[i][j] + d[j][i]);
        
  if(ans == INF) ans = -1;
  cout << ans;
}