#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[102];                //미로
bool vis[102][102];               //방문여부
int len[102][102];                //경로 길이
int dx[4] = {1,0,-1,0};           //상하좌우
int dy[4] = {0,1,0,-1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin>>board[i];              //숫자가 붙어있어 string으로 입력 받음
  }
  queue <pair<int, int>> q;
  q.push({0,0});
  len[0][0]=1;
  vis[0][0] = 1;
  while(!q.empty()) {
    pair<int, int> cur = q.front(); q.pop();
    for (int dir = 0 ; dir <4;dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >=n || ny < 0 || ny >=m) continue;
      if (vis[nx][ny] || board[nx][ny] != '1') continue;    //board가 string 이므로 1이 아니라 '1'이어야 함
      len[nx][ny] = len[cur.X][cur.Y]+1;
      vis[nx][ny] = 1;
      q.push({nx,ny});
    }
  }
  cout << len[n-1][m-1];
}
