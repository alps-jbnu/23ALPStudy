#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[205][205];
bool vis[205][205];

priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
queue<pair<int, int>> q;

int N, K;
int S, X, Y;
int _time = -1;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];

			if (board[i][j] != 0) {
				pq.push({ board[i][j],{i, j}});
				vis[i][j] = 1;
			}
		}
	}

	cin >> S >> X >> Y;

	while (!pq.empty() || !q.empty()) {
		_time++; // if time == S 일때 정답 출력
		if (_time == S) {
			break;
		}
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			q.push({ cur.second.first, cur.second.second });
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (vis[nx][ny] || board[nx][ny] != 0) continue;

				vis[nx][ny] = true;
				board[nx][ny] = board[cur.first][cur.second];
				pq.push({ board[nx][ny],{nx, ny} });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << board[X-1][Y-1];
}
