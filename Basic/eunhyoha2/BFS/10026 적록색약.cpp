#include <iostream>
using namespace std;

int N;
string map[101];
int visit[101][101];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (visit[nx][ny] == 0 && map[nx][ny] == map[x][y]) {
			visit[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	int cnt_normal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				cnt_normal++;
				visit[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << cnt_normal << " ";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G')map[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}

	int cnt_abnormal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				cnt_abnormal++;
				visit[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << cnt_abnormal;

	return 0;
}