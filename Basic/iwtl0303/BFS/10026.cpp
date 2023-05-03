#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102]; 
bool vis[102][102];           
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int> > Q;
int n;
void bfs(int x,int y){
  vis[x][y] = true;
  Q.push({x,y});
  while (!Q.empty()) {
      auto cur = Q.front(); Q.pop();
      for (int dir =0; dir <4;dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //구역이 n*n인 정사각형이므로
        if (vis[nx][ny] || board[nx][ny] != board[x][y]) continue;  //서로 다른 구역이면 스킵
        vis[nx][ny] =true;
        Q.push({nx,ny});
      }
    }
}
int area(){
  int cnt = 0;
  for (int i =0 ; i<n; i++){
    for (int j =0; j<n; j++){
      if (!vis[i][j]){
        cnt++;
        bfs(i,j);
      }
    }
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin>> board[i];
  int not_g = area(); //적록색약이 아닌 사람
  for(int i=0;i<n;i++) fill(vis[i],vis[i]+n,false);
  for (int i=0;i<n;i++){
    for (int j =0;j<board[i].length();j++){
      if (board[i][j] == 'G') board[i][j] = 'R';    //적록색약은 빨강과 초록을 구분못하니 초록을 빨강으로 바꿔줌
    }
  }
  int is_g = area(); //적록색약인 사람
  cout << not_g << " "<<is_g;
  return 0;
}
