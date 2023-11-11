#include <iostream>
#include <algorithm>
using namespace std;

int T, M, N, K, x, y;
int cnt = 0;
int field[50][50];
int xfield[4] = { 0, 0, -1, 1 };
int yfield[4] = { 1, -1, 0, 0 };

//1로 표시된 영역 찾아, 0으로 변경
void dfs(int x, int y) { 
	field[x][y] = 0;
	for (int i = 0; i < 4; i++) { //상하좌우 이동한 새로운 위치 계산
		int xx = x + xfield[i];
		int yy = y + yfield[i];
		if (xx < 0 || yy < 0 || xx >= M || yy >= N) continue;
		if (field[xx][yy] == 1) {
			dfs(xx, yy);
		}
	}
}

int main() {
	cin >> T;
	for (int q = 0; q < T; q++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			field[x][y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		//영역 0으로 초기화
		for (int i = 0; i < M; i++) {
			fill(field[i], field[i] + N, 0);
		}
	}

}

