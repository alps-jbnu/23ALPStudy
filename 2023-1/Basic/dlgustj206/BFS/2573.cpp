#include <iostream>
#include <queue>
#include <cstring>
#define X first
#define Y second
using namespace std;

int ice[301][301];
int vis[301][301];
int num[301][301];
int n, m;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

void check(int, int);
void meltIce();

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}

	int year = 0;
	while (1) {
        //빙산 녹이기
        year++;
		meltIce();
		memset(vis, 0, sizeof(vis));

        //빙산 개수
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && ice[i][j] != 0) {
					check(i, j);
					cnt++;
				}
			}
		}

		if (cnt == 0) {
			cout << 0 << '\n';
			return 0;
		}
		else if (cnt == 1) continue;
        else break;
	}
    cout << year << '\n';
	return 0;
}

void check(int i, int j){
	queue<pair<int, int>>Q;
	Q.push({i, j});

	while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();

		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(ice[nx][ny]==0||vis[nx][ny]!=0) continue;
            Q.push({nx, ny});
            vis[nx][ny]=1;
		}
	}
}

void meltIce(){
	memset(num, 0, sizeof(num));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] == 0) continue;
			for (int k = 0; k < 4; k++) {
                int nx=i+dx[k];
                int ny=j+dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (ice[nx][ny] == 0) num[i][j]++;
			}
		}
	}

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
			ice[i][j]=max(0, ice[i][j]-num[i][j]);   
}