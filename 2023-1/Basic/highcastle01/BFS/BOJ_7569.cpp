#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[101][101][101];
int iken[101][101][101];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main(void)
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   queue<pair<pair<int, int>, int>> check;
   
   int n, m, h, i, j, k;
   
   cin >> m >> n >> h;
   
   for(i = 0; i < h; i++)
   {
      for(j = 0; j < n; j++)
      {
         for(k = 0; k < m; k++)
         {
            cin >> board[j][k][i];
            if(board[j][k][i] == 1)
            {
               check.push({{j, k}, i});
            }
            if(board[j][k][i] == 0)
            {
               iken[j][k][i] = -1;
            }
         }
      }
   }
   
   while(!check.empty())
   {
      pair<pair<int, int>, int> cur = check.front(); check.pop();
      for(int dir = 0; dir < 6; dir++)
      {
         int nx = cur.X.X + dx[dir];
         int ny = cur.X.Y + dy[dir];
         int nz = cur.Y + dz[dir];
         
         if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
         {
            continue;
         }
         if(iken[nx][ny][nz] >= 0)
         {
            continue;
         }
         iken[nx][ny][nz] = iken[cur.X.X][cur.X.Y][cur.Y] + 1;
         check.push({{nx, ny}, nz});
      }
   }
   
   int Max = 0;
   for(i = 0; i < h; i++)
   {
      for(j = 0; j < n; j++)
      {
         for(k = 0; k < m; k++)
         {
            if(iken[j][k][i] == -1)
            {
               cout << -1 << "\n";
               return 0;
            }
            Max = max(Max, iken[j][k][i]);
         }
      }
   }
   
   cout << Max;
   
   return 0;
   
}
