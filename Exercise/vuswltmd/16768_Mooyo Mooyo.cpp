#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[105][15];
bool vis[105][15];
queue<pair<int, int>> Q;
int N, K;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
		}
	}
	while (true) {
		bool change = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] != '0' && vis[i][j] == 0) {
					Q.push({ i,j });
					vis[i][j] = 1;
					char color = board[i][j];
					int haybales_count = 0;

					while (!Q.empty()) {
						auto cur = Q.front(); Q.pop();
						haybales_count++;

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= 10) continue;
							if (vis[nx][ny] || board[nx][ny] != color) continue;
							vis[nx][ny] = true;
							Q.push({ nx, ny });
						}
					}

					if (haybales_count >= K) {
						change = true;
						for (int i = 0; i < N; i++) {
							for (int j = 0; j < 10; j++) {
								if (vis[i][j] == 1) {
									board[i][j] = '0';
								}
							}
						}
					}

					for (int i = 0; i < N; i++) {
						for (int j = 0; j < 10; j++) {
							vis[i][j] = 0;
						}
					}
				}
			}
		}

		for (int j = 0; j < 10; j++) {
			queue<char> gravity_q;
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j] != '0') {
					gravity_q.push(board[i][j]);
				}
			}

			for (int i = N - 1; i >= 0; i--) {
				if (!gravity_q.empty()) {
					board[i][j] = gravity_q.front();
					gravity_q.pop();
				}
				else {
					board[i][j] = '0';
				}
			}
		}

		if (change == false) {
			break;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}
