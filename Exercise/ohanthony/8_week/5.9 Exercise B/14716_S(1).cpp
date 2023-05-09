#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

int M, N;
int result;
int board[255][255];
bool vis[255][255];

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (vis[i][j] || board[i][j] == 0) continue;

      vis[i][j] = true;
      result++;
      stack<pii> s;
      s.push({i, j});

      while (!s.empty()) {
        auto cur = s.top();
        s.pop();

        for (int dir = 0; dir < 8; dir++) {
          int nx = dx[dir] + cur.X;
          int ny = dy[dir] + cur.Y;

          if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
          if (vis[nx][ny] || board[nx][ny] == 0) continue;

          vis[nx][ny] = true;
          s.push({nx, ny});
        }
      }
    }
  }

  cout << result;
  return 0;
}