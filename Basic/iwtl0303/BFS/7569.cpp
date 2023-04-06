#include <bits/stdc++.h>
using namespace std;
int board[102][102][102];            //토마토밭
int dist[102][102][102];             //토마토 판단 & 걸린 날짜 저장
int dx[6] = {1,0,-1,0,0,0};          //상하좌우앞뒤
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m,n,h;
  cin >> m >> n >> h;
  queue<tuple<int,int,int>> Q;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < n; j++) {
      for (int k = 0; k<m;k++){
        cin >> board[j][k][i];
        if (board[j][k][i] == 1) Q.push({j,k,i});    //토마토 입력과 동시에 큐에 넣어 동시에 BFS를 할 수 있다.
        if (board[j][k][i] == 0) dist[j][k][i] = -1;  //익지 않은 토마토

      }
    }
  }
  while (!Q.empty()){
    auto cur = Q.front(); Q.pop();
    int curX,curY,curZ;
    tie(curX,curY,curZ) = cur;
    for (int dir =0 ; dir < 6 ; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || nx>=n || ny<0 || ny>=m || nz<0 || nz >= h) continue;
      if (dist[nx][ny][nz] >= 0 ) continue;
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
      Q.push({nx,ny,nz});
  }
}
int ans = 0;
for (int i=0;i<h;i++) {
  for (int j=0;j<n;j++){
    for (int k=0;k<m;k++){
      if (dist[j][k][i] == -1){                   //-1이면 익지 않는 토마토이니 -1 출력
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[j][k][i]);
    }
  }
}
cout << ans;
}
