#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int t[35];
int n, m, r;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  for(int i = 1;i<=n;i++) fill(d[i],d[i]+1+n,INF);
  for(int i = 1;i<=n;i++) cin >> t[i];
  while(r--){
    int a,b,l;
    cin >> a >> b >> l;
    d[a][b] = min(d[a][b], l);
    d[b][a] = min(d[b][a], l);
  }
  for(int i = 1;i<=n;i++) d[i][i] = 0;

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
  
  int ans = 0;
  for(int k = 1;k<=n;k++){
    int sum = 0;
    for(int i = 1;i<=n;i++){
        if(d[k][i] <= m) sum += t[i];
    }
    ans = max(ans, sum);
  }
  cout << ans;

  // 예은이가 k=1~n까지 낙하한 경우
  // d[k][i]>=m이면 ans += t[i]
  // 길은 양방향 통행 가능!!

}
