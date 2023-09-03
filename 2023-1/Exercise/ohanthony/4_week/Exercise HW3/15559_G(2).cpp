#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, result;

string board[1005];
int gift[1005][1005];

int dirCode(char dir) {
  if (dir == 'N')
    return 0;
  else if (dir == 'S')
    return 1;
  else if (dir == 'W')
    return 2;
  else
    return 3;
}

void dfs(int x, int y, int giftCode) {
  gift[x][y] = giftCode;

  // 해당 방향 설정
  int dir = dirCode(board[x][y]);
  int nx = x + dx[dir];
  int ny = y + dy[dir];

  if (!gift[nx][ny])
    dfs(nx, ny, giftCode);
  else if (gift[nx][ny] == giftCode)
    result++;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> board[i];

  int giftCode = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (gift[i][j]) continue;

      giftCode++;
      dfs(i, j, giftCode);
    }
  }

  cout << result;

  return 0;
}
