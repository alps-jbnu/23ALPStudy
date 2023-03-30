#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int board[10][10];
map<int, int> m;
int result;

void dfs(int x, int y, int len, int num) {
  if (len == 6) {
    if (!m[num]) {
      m[num]++;
      result++;
    }

    return;
  }

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
      continue;

    dfs(nx, ny, len + 1, board[nx][ny] + 10 * num);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      dfs(i, j, 0, 0);
    }
  }

  cout << result << '\n';

  return 0;
}