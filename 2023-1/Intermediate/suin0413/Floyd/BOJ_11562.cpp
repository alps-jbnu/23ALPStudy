#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[255][255];
int n, m, t;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1;i<=n;i++) fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = 0;
    if(c == 1) d[b][a] = 0;
    else d[b][a] = min(d[b][a], 1);
  }  
  for(int i =1;i<=n;i++) d[i][i] = 0;
  
  for(int k = 1;k<=n;k++)
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  cin >> t;
  while(t--){
    int s, e;
    cin >> s >> e;
    cout << d[s][e] << "\n";
  }
}
