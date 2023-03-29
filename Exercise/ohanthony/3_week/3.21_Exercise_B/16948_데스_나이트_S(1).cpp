#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};

int n;
int r1, c1, r2, c2;

queue<pii> q;
int len[205][205];

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> r1 >> c1 >> r2 >> c2;

  memset(len, -1, sizeof(len));  // 모든 값 초기화

  q.push({r1, c1});
  len[r1][c1] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 6; dir++) {
      int nr = cur.X + dr[dir];
      int nc = cur.Y + dc[dir];

      if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      if (len[nr][nc] > -1) continue;

      if (nr == r2 && nc == c2) {  // 목적지에 도달할 경우
        cout << len[cur.X][cur.Y] + 1;
        return 0;
      }

      q.push({nr, nc});
      len[nr][nc] = len[cur.X][cur.Y] + 1;
    }
  }

  cout << -1;
  return 0;
}