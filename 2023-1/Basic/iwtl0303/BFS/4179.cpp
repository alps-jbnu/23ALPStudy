#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];               //미로
int dist1[1002][1002];            //불이 번진 시간 
int dist2[1002][1002];            //지훈이의 이동 시간
int dx[4] = {1,0,-1,0};           //상하좌우
int dy[4] = {0,1,0,-1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  queue<pair<int,int>> Q1;          //불
  queue<pair<int,int>> Q2;          //지훈
  for (int i = 0; i < n; i++){
    fill (dist1[i], dist1[i]+m, -1);
    fill (dist2[i], dist2[i]+m, -1);
  }
  for (int i = 0; i < n; i++){
      cin >> board[i];
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (board[i][j]=='F'){
        Q1.push({i,j});
        dist1[i][j] = 0;
      }
      if (board[i][j]=='J'){
        Q2.push({i,j});
        dist2[i][j] = 0;
      }
    }
  }
  while (!Q1.empty()){  //불의 BFS
    auto cur = Q1.front(); Q1.pop();
    for (int dir =0 ; dir < 4 ; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx>=n || ny<0 || ny>=m) continue;
      if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
      Q1.push({nx,ny});
    }
  }
  while (!Q2.empty()){  //지훈이의 BFS
    auto cur = Q2.front(); Q2.pop();
    for (int dir =0 ; dir < 4 ; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx>=n || ny<0 || ny>=m){  //범위를 벗어나면 탈출
        cout << dist2[cur.X][cur.Y]+1;
        return 0;
      }
      if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue; //불의 시간보다 지훈이의 시간이 오래 걸린경우
      dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
      Q2.push({nx,ny});
    }
  }
  cout<<"IMPOSSIBLE"; //이곳에 도달하면 탈출 못함
}
