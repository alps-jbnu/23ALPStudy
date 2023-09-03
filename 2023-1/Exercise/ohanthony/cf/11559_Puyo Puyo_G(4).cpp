#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

string board[20];
bool vis[20][20];
queue<pii> q;

int result; // 일어난 연쇄의 수를 저장하는 변수

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 12; i++) {
    cin >> board[i];
  }

  while (1) {
    memset(vis, false, sizeof(vis));
    bool isBoom = false;

    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (vis[i][j] || board[i][j] == '.') {
          continue;
        }

        q.push({i, j});
        vis[i][j] = true;

        char color = board[i][j]; // 탐색하는 color가 무엇인지 저장
        stack<pii> boom; // 같은 color가 4개 이상인 경우 터지는 좌표 저장

        while (!q.empty()) {
          auto cur = q.front();
          q.pop();

          boom.push({cur.X, cur.Y});

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
              continue;
            if (vis[nx][ny] || board[nx][ny] != color)
              continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
          }
        }

        // 같은 color의 수가 4인 경우 해당 color을 '.'을 바꿈
        if (boom.size() >= 4) {
          isBoom = true;

          while (!boom.empty()) {
            int x = boom.top().X;
            int y = boom.top().Y;
            boom.pop();

            board[x][y] = '.';
          }
        }
      }
    }

    if (isBoom)
      result++;

    // gravity 처리
    for (int y = 0; y < 6; y++) {
      queue<char> gravity;

      for (int x = 11; x >= 0; x--) {
        if (board[x][y] != '.') {
          gravity.push(board[x][y]);
        }
      }

      int x = 11;
      while (!gravity.empty()) {
        auto cur = gravity.front();
        gravity.pop();

        board[x--][y] = cur;
      }

      while (x >= 0) {
        board[x--][y] = '.';
      }
    }

    if (!isBoom)
      break;
  }

  cout << result;
  return 0;
}
