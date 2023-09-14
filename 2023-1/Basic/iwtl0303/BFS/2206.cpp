#include <bits/stdc++.h>        
using namespace std;
#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char board[1000][1000];
int dist[1000][1000][2];
int n,m;

bool OOB(int x, int y){ //true면 범위 벗어남
  return x<0 || x>=n || y<0 || y>=m;
}

int bfs() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      dist[i][j][0] = dist[i][j][1] = -1;
  dist[0][0][0] = dist[0][0][1] = 1;
  queue<tuple<int, int, int>> q;
  q.push({0,0,0});
  while (!q.empty()) {
    int x, y, broken;
    tie(x, y, broken) = q.front();
    if(x == n-1 && y == m-1) return dist[x][y][broken];
    q.pop();
    int nextdist = dist[x][y][broken] + 1;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(OOB(nx, ny)) continue;      
      if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
        dist[nx][ny][broken] = nextdist;
        q.push({nx, ny, broken});
      }      
      // (nx, ny)를 부수는 경우
      if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
        dist[nx][ny][1] = nextdist;
        q.push({nx, ny, 1});
      }      
    }
  }
  return -1;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j]; //char이므로 한개씩 입력가능
  cout << bfs();
  return 0;
}
