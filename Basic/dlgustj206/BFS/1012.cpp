#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[51][51];
int vis[51][51];
int t, n, m, k, x, y;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

void bfs(int, int);

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    cin >> m >> n >> k;
    int x, y;
    for (int i = 0; i < k; i++){
      cin >> x >> y;
      board[y][x] = 1;
    }
    int num=0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] == 1 && !vis[i][j]){
          bfs(i, j);
          num++;
        }
      }
    }
    cout << num << "\n";
    for(int i = 0; i < n; i++){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, 0);
    }
  }
}

void bfs(int x, int y){
  queue <pair<int, int >> Q;
  vis[x][y] = 1;
  Q.push({x, y});
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}