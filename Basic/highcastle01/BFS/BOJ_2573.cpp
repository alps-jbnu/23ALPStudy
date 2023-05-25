#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m;
int Map[301][301];
int tmap[301][301];
bool vis[301][301];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	
	q.push({x, y});
	vis[x][y] = true;
	
	while(!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if(vis[nx][ny] == false && Map[nx][ny] != 0)
				{
					vis[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

int melting(int x, int y)
{
	int cnt = 0, i;
	
	for(i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(Map[nx][ny] == 0)
		{
			cnt++;
		}
	}
	
	return cnt;
}

void solution()
{
	int year = 0, i, j;
	while(1)
	{
		int land = 0;
		memset(vis, false, sizeof(vis));
		memset(tmap, 0, sizeof(tmap));
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(Map[i][j] != 0 && vis[i][j] == false)
				{
					land++;
					bfs(i, j);
				}
			}
		}
		
		if(land >= 2)
		{
			cout << year << "\n";
			break;
		}
		if(land == 0)
		{
			cout << 0 << "\n";
			break;
		}
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(Map[i][j] != 0)
				{
					tmap[i][j] = Map[i][j] - melting(i, j);
					if(tmap[i][j] < 0)
					{
						tmap[i][j] = 0;
					}
				}
			}
		}
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				Map[i][j] = tmap[i][j];
			}
		}
		
		year++;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, j;
	
	cin >> n >> m;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solution();
	
	return 0;
}
