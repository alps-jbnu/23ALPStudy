#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, k;

bool vis[105][10];
string cell[105];
queue<pii> q;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> cell[i];
  }

  while (1) {
    memset(vis, false, sizeof(vis));
    bool turn_into_zero = false;

    // 1. gravity 하기 전 인접한 haybale 갯수가 k개 이상인지 판별
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10; j++) {
        if (cell[i][j] == '0' || vis[i][j])
          continue;

        q.push({i, j});
        vis[i][j] = true;

        char color = cell[i][j]; // 탐색하는 color값 저장
        stack<pii>
            count; // 같은 숫자가 연달아 나오는지 파악하기 위해 stack 활용

        while (!q.empty()) {
          auto cur = q.front();
          q.pop();

          count.push({cur.X, cur.Y});

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= 10)
              continue;
            if (cell[nx][ny] != color || vis[nx][ny])
              continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
          }
        }

        // k 이상일 경우 turn_into_zero
        if (count.size() >= k) {
          turn_into_zero = true;
          while (!count.empty()) {
            int x = count.top().X;
            int y = count.top().Y;
            count.pop();

            cell[x][y] = '0';
          }
        }
      }
    }

    // 2. gravity, 밑으로 채우는 거여서 이중 for문의 시작점을 주의
    for (int j = 0; j < 10; j++) {
      queue<char> gravity;

      for (int i = n - 1; i >= 0; i--) {
        if (cell[i][j] != '0')
          gravity.push(cell[i][j]);
      }

      int x = n - 1;
      while (!gravity.empty()) {
        auto cur = gravity.front();
        gravity.pop();

        cell[x--][j] = cur;
      }

      // 기존의 있는 값에다가 0을 채움
      while (x >= 0) {
        cell[x--][j] = '0';
      }
    }

    if (turn_into_zero == false)
      break;
  }

  // 3. 최종 값 출력
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      cout << cell[i][j];
    }
    cout << '\n';
  }

  return 0;
}
