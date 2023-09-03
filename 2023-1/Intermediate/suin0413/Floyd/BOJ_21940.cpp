#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[205][205];
int c[205];
int mx[205];
int n, m, p;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1;i<=n;i++) fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
  }
  for(int i = 1;i<=n;i++) d[i][i] = 0;
  for(int k = 1;k<=n;k++)
    for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  cin >> p;
  for(int i = 1;i<=p;i++) cin >> c[i];

  int ans = INF;
  for(int k = 1;k<=n;k++){ // 도시별로
    for(int i = 1;i<=p;i++){ // 왕복 시간
      mx[k] = max(mx[k], d[k][c[i]] + d[c[i]][k]);
    }
    ans = min(ans, mx[k]);
  }

  for(int i = 1;i<=n;i++) if(mx[i] == ans) cout << i << " ";

  // 문제가 너무 이해하기 어려웠음..
  // 제일 고생하는 애가 그나마 덜 고생할 수 있는 도시 X를 구하는 것이었다 '-'
}
