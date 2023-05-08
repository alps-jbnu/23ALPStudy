#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];              //그림판
bool vis[502][502];               //방문여부
int dx[4] = {1,0,-1,0};           //상하좌우
int dy[4] = {0,1,0,-1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  queue<pair<int,int> > q;
  for (int i=0; i<n; i++){        //그림 입력
    for (int j=0; j<m; j++){
      cin>>board[i][j];
    }
  }
  int mx=0,num=0;
  for (int i=0; i<n; i++){        //모든 요소 확인
    for (int j=0; j<m; j++){
      if (board[i][j] == 0 || vis[i][j]) continue;  //그림이 아니거나 방문했으면 패스
      num++;      //그림 개수 세기
      vis[i][j] = 1;  //방문 표시
      q.push({i,j});  //큐 입력
      int cnt=0;      //그림의 크기
      while (!q.empty()){ //큐가 빌때까지 반복
        cnt++;            //그림 크기 세기
        pair<int,int> cur = q.front(); q.pop(); //현재 좌표 저장
        for (int dir = 0; dir < 4;dir++){       //좌표에서 상하좌우 확인
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >=n || ny < 0 || ny >=m) continue;
          if (vis[nx][ny] || board[nx][ny] != 1) continue;
          vis[nx][ny] = 1;                      //미방문 시 방문 표시
          q.push({nx,ny});                      //다음에 확인할 좌표 큐에 저장
        }
      }
      mx = max(mx,cnt);                         //가장 큰 그림 크기 저장
    }
  }
  cout << num << '\n' << mx;
}
