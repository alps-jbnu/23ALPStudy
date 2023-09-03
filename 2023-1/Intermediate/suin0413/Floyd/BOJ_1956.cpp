#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[405][405];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1;i<=n;i++) fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
  }

  for(int i = 1;i<=n;i++) d[i][i] = 0;

  for(int k = 1;k<=n;k++)
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
  int ans = INF;
  for(int k = 1;k<=n;k++){
    for(int i = k+1;i<=n;i++){
        if(d[k][i] != INF && d[i][k] != INF) ans = min(ans, d[k][i] + d[i][k]);
    }
  }
  if(ans == INF) cout << "-1";
  else cout << ans;

}
