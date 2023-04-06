#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, i, j;
	
	cin >> t;
	
	for(i = 0; i < t; i++)
	{
		bool vis[51][51] = {};
		int board[51][51] = {};
		int n, m, dir, nx, ny, K, l, ix, jx, jirong = 0;
		cin >> m >> n >> K;
		for(j = 0; j < K; j++)
		{
			cin >> ix >> jx;
			board[jx][ix] = 1;
		}
		
		for(j = 0; j < n; j++)
		{
			for(l = 0; l < m; l++)
			{
				if(board[j][l] == 1 && !vis[j][l])
				{
					jirong++;
					vis[j][l] = true;
					queue<pair<int, int>> check;
					check.push({j, l});
					while(!check.empty())
					{
						pair<int, int> cur = check.front(); check.pop();
						
						for(dir = 0; dir < 4; dir++)
						{
							nx = cur.X + dx[dir];
							ny = cur.Y + dy[dir];
							
							if(nx < 0 || nx >= n || ny < 0 || ny >= m)
							{
								continue;
							}
							if(vis[nx][ny] || board[nx][ny] == 0)
							{
								continue;
							}
							vis[nx][ny] = true;
							check.push({nx, ny});
						}
					}
				}
			}
		}
		cout << jirong << "\n";
	}
	return 0;
}
