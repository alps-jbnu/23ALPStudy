#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int cabbage[52][52] = {0}; // 1이 배추있음, 0이 없음  
bool vis[52][52]; // 해당 칸을 방문했는지 여부를 저장
int t, n, m, k;
int x, y; 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	cin >> t;
  	while(t--) {
  		cin >> m >> n >> k;
	
  		for(int i = 0; i < k; i++) {
  			cin >> x >> y;
			cabbage[x][y] = 1;	
		}
      		
 		int num = 0; // 필요한지렁이의 수
 		
		for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) { // (i, j)를 시작점으로 하고 싶은 상황
      			if(cabbage[i][j] == 0 || vis[i][j]) continue; // 해당 칸이 양배추가 없는 부분(0)이거나 이미 (i, j)를 방문했을 경우 넘어감
      			// (i,j)는 새로운 양배추무리에 속해있는 시작점
      			num++; // 지렁이 수 1 증가
      			queue<pair<int,int> > Q;
      			vis[i][j] = 1; // (i,j)로 BFS를 시작하기 위한 준비
      			Q.push({i,j});
      			
      			while(!Q.empty()) {
        			pair<int,int> cur = Q.front(); Q.pop();
        			for(int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
          				int nx = cur.X + dx[dir];
          				int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
          				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
          				if(vis[nx][ny] || cabbage[nx][ny] != 1) continue; // 이미 방문한 칸이거나 배추가있는칸이 아닐 경우
          				vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
          				Q.push({nx,ny});
        			}
      			}
      			// (i, j)를 시작점으로 하는 BFS가 종료됨
    		}
  		}
  		cout << num <<'\n';
  		for(int i = 0; i < n; i++) {
  			fill(cabbage[i], cabbage[i]+m, 0);
  			fill(vis[i], vis[i]+m, false);
		}
	}
}
