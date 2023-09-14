#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];            //토마토밭
int dist[1002][1002];             //토마토 판단 & 걸린 날짜 저장
int dx[4] = {1,0,-1,0};           //상하좌우
int dy[4] = {0,1,0,-1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int M,N;
  cin >> M >> N;
  queue<pair<int,int>> Q;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) Q.push({i,j});    //토마토 입력과 동시에 큐에 넣어 동시에 BFS를 할 수 있다.
      if (board[i][j] == 0) dist[i][j] = -1;  //익지 않은 토마토
    }
  }
  while (!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for (int dir =0 ; dir < 4 ; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx>=N || ny<0 || ny>=M) continue;
      if (dist[nx][ny] >= 0 ) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
  }
}
int ans = 0;
for (int i=0;i<N;i++) {
  for (int j=0;j<M;j++){
    if (dist[i][j] == -1){                   //-1이면 익지 않는 토마토이니 -1 출력
      cout << -1;
      return 0;
    }
    ans = max(ans, dist[i][j]);
  }
}
cout << ans;
}
