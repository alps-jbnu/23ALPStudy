#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int r, c, k;
int result;

string arr[10];
bool vis[10][10];

void dfs(int x, int y, int len) {
  if (x == 0 && y == c - 1 && len == k) {
    result++;
    return;
  }

  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if (arr[nx][ny] == 'T' || vis[nx][ny]) continue;

    vis[nx][ny] = true;
    dfs(nx, ny, len + 1);
    vis[nx][ny] = false;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c >> k;
  for (int i = 0; i < r; i++) cin >> arr[i];

  vis[r - 1][0] = true;
  dfs(r - 1, 0, 1);

  cout << result;
  return 0;
}