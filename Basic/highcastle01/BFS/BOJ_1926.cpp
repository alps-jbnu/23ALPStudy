#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, j, n, m, pmx = 0, pnum = 0, dir, nx, ny;
	queue<pair<int, int>> check;
	cin >> n >> m;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(board[i][j] == 0 || vis[i][j])
			{
				continue;
			}
			pnum++;
			vis[i][j] = 1;
			check.push({i, j});
			int parea = 0;
			while(!check.empty())
			{
				parea++;
				pair<int, int> cur = check.front(); check.pop();
				for(dir = 0; dir < 4; dir++)
				{
					nx = cur.X + dx[dir];
					ny = cur.Y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						continue;
					}
					if(vis[nx][ny] || board[nx][ny] != 1)
					{
						continue;
					}
					vis[nx][ny] = 1;
					check.push({nx, ny});
				}
			}
			pmx = max(pmx, parea);
		}
	}
	
	cout << pnum << "\n" << pmx;
	
	return 0;
}
