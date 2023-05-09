#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dist[301][301];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int>> check;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i, I, x, y, x2, y2, k;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> I;
		for(k = 0; k < I; k++)
		{
			fill(dist[k], dist[k] + I, 0);
		}
		
		cin >> x >> y;
		dist[x][y] = 1;
		check.push({x, y});
		cin >> x2 >> y2;
		
		while(!check.empty())
		{
			pair<int, int> cur = check.front(); check.pop();
			for(int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				
				if(nx < 0 || nx >= I || ny < 0 || ny >= I)
				{
					continue;
				}
				if(dist[nx][ny] == 0)
				{
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					check.push({nx, ny});
				}
			}
		}
		
		cout << dist[x2][y2] - 1 << "\n";
	}
	
	return 0;
}
