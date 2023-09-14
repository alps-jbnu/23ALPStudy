#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

char board[101][101];
bool vis[101][101];
queue<pair<int, int>> check;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n;

void bfs(int x, int y)
{
    int dir, nx, ny, area = 0;
    vis[x][y] = true;
    check.push({x, y});

    while(!check.empty())
    {
        pair<int, int> cur = check.front(); check.pop();
        for(dir = 0; dir < 4; dir++)
        {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }
            if(!vis[nx][ny] && board[x][y] == board[nx][ny])
            {
                vis[nx][ny] = true;
            	check.push({nx, ny});
            }
        }
    }
}



int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
	int i, j, normal = 0, rg = 0;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(!vis[i][j])
			{
				bfs(i, j);
				normal++;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		fill(vis[i], vis[i]+n, false);
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(board[i][j] == 'G')
			{
				board[i][j] = 'R';
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(!vis[i][j])
			{
				bfs(i, j);
				rg++;
			}
		}
	}
	
	cout << normal << " " << rg;
	
	return 0;
}
