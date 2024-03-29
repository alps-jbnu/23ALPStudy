#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int d[202][202];
int nxt[202][202];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    fill(d[i], d[i] + n + 1, INF);
    d[i][i] = 0;
  }

  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = d[b][a] = c;
    nxt[a][b] = b;
    nxt[b][a] = a;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++){
        int tmp = d[i][k] + d[k][j];
        if(tmp < d[i][j]) {
          d[i][j] = tmp;
          nxt[i][j] = nxt[i][k];
        }
      }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j) cout << "- ";
      else cout << nxt[i][j] << ' ';
    }
    cout << '\n';
  }
}