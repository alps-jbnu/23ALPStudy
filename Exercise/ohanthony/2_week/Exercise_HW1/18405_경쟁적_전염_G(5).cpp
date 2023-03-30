#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, k, s, x, y;

int lab[205][205];
vector<pair<int, pii>> temp;

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> lab[i][j];

      // 바이러스 인 것만 temp에 넣어줌
      if (lab[i][j]) temp.push_back({lab[i][j], {i, j}});
    }
  }

  // 바이러스를 오름차순으로 정렬
  sort(temp.begin(), temp.end());

  cin >> s >> x >> y;

  while (s--) {
    int tempSize = temp.size();
    for (int i = 0; i < tempSize; i++) {
      for (int dir = 0; dir < 4; dir++) {
        int nx = temp[i].Y.X + dx[dir];
        int ny = temp[i].Y.Y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (lab[nx][ny]) continue;

        lab[nx][ny] = temp[i].X;
        temp.push_back({temp[i].X, {nx, ny}});
      }
    }

    // 중복 확인을 방지하기 위한 처리
    temp.erase(temp.begin(), temp.begin() + tempSize);
  }

  cout << lab[x - 1][y - 1];

  return 0;
}
