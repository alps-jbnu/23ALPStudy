#include <iostream>
#include <queue>
using namespace std;

char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

int main(void) {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	cin >> n;
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
    	cin >> board[i][j];
    	}
  	}
  	
  	int cnt = 0;
  	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
      		if (!vis[i][j]) {
        		cnt++;
        		queue<pair<int, int> > Q;
  				Q.push({ i,j });
  				vis[i][j] = 1;
  				while (!Q.empty()) {
    				int x = Q.front().first;
    				int y = Q.front().second;
    				Q.pop();
    				for (int dir = 0; dir < 4; dir++) {
      					int nx = x + dx[dir];
      					int ny = y + dy[dir];
      					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      					if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
      					vis[nx][ny] = 1;
      					Q.push({ nx,ny });
    				}
  				} 
      		}
    	}
  	}
  	
  	int num = cnt; //적록색약이 아님  

  	// 방문배열 초기화
  	for(int i = 0; i < n; i++)
    	fill(vis[i], vis[i]+n, false);
  
  	// 초록이면 빨강으로 바꿔줌
  	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
      	if (board[i][j] == 'G')
        	board[i][j] = 'R';
    	}
  	}
	
	cnt = 0;
  	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
      		if (!vis[i][j]) {
        		cnt++;
        		queue<pair<int, int> > Q;
  				Q.push({ i,j });
  				vis[i][j] = 1;
  				while (!Q.empty()) {
    				int x = Q.front().first;
    				int y = Q.front().second;
    				Q.pop();
    				for (int dir = 0; dir < 4; dir++) {
      					int nx = x + dx[dir];
      					int ny = y + dy[dir];
      					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      					if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
      					vis[nx][ny] = 1;
      					Q.push({ nx,ny });
    				}
  				} 
      		}
    	}
  	}

  	int jjj = cnt; //적록색맹  
  	cout << num << " " << jjj;
  	return 0;
}
