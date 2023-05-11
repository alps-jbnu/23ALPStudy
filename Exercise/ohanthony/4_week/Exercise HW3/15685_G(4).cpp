#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int board[105][105];

int n, x, y, d, g, result;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  while (n--) {
    vector<int> dir;
    cin >> x >> y >> d >> g;
    board[x][y] = 1;  // 커브가 지나온 길을 1로 표시

    x += dx[d];
    y += dy[d];
    board[x][y] = 1;
    dir.push_back(d);

    while (g--) {
      int dragonSize = dir.size();
      for (int i = dragonSize - 1; i >= 0; i--) {
        int temp = (dir[i] + 1) % 4;
        x += dx[temp];
        y += dy[temp];
        board[x][y] = 1;
        dir.push_back(temp);
      }
    }
  }

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] && board[i + 1][j] == 1) result++;
    }
  }

  cout << result;
  return 0;
}

/*
- g = 0 / 0
- g = 1 / 0 1(0+1)
- g = 2 / 0 1 2(1+1) 1(0+1)
- g = 3 / 0 1 2 1 2(1+1) 3(2+1) 2(1+1) 1(0+1)
*/