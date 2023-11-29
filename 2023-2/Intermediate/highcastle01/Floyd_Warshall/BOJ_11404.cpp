#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dist[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, i, j, k;
  
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        fill(dist[i], dist[i] + 1 + n, INF);
    }
    
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    
    for(i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
      
    for(i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
          if(dist[i][j] == INF)
          {
              cout << "0 ";
          }
          else
          {
              cout << dist[i][j] << ' ';
          }
        }
        cout << '\n';
    }
    
    return 0;
}
