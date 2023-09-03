#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[1001][1001];
int iken[1001][1001] = {0,};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   queue<pair<int, int>> check;
   
   int n, m, dir, i, j, nx, ny, cnt = 0;
   
   cin >> m >> n;
   
   for(i = 0; i < n; i++)
   {
      for(j = 0; j < m; j++)
      {
         cin >> board[i][j];
         if(board[i][j] == 1)
         {
            check.push({i, j});
            iken[i][j] = 1;
         }
         else if(board[i][j] == -1)
         {
            iken[i][j] = -1;
         }
      }
   }
   
   for(i = 0; i < n; i++)
   {
      for(j = 0; j < m; j++)
      {
         if(board[i][j] == -1)
         {
            iken[i][j] = -1;
         }
      }
   }

   while(!check.empty())
   {
      pair<int, int> cur = check.front(); check.pop();
      
      for(dir = 0; dir < 4; dir ++)
      {
         nx = cur.X + dx[dir];
         ny = cur.Y + dy[dir];
         
         if(nx < 0 || nx >= n || ny < 0 || ny >= m)
         {
            continue;
         }
         if(iken[nx][ny] == 0 && board[nx][ny] == 0)
         {
            iken[nx][ny] = iken[cur.X][cur.Y] + 1;
            check.push({nx, ny});
         }
      }
   }
   
   int Max = 0;
   for(i = 0; i < n; i++)
   {
  		for(j = 0; j < m; j++)
  		{
  			if(iken[i][j] == 0)
  			{
  				cout << -1;
  				return 0;
			}
			Max = max(Max, iken[i][j]);
	    }
   }
   
   cout << Max - 1;
   
   return 0;
}
