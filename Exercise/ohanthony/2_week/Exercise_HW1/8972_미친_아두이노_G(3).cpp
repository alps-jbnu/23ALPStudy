#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int r, c;
string board[105];
string position;  // ㅈㅅ가 움직여야 하는 방향

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> board[i];
  cin >> position;

  // ㅈㅅ가 움직일려는 위치의 길이 만큼 for문 반복
  for (int i = 0; i < position.length(); i++) {
    int Ix, Iy;              // ㅈㅅ의 원래 위치 저장
    queue<pii> q;            // ㅁㅊ 아두이노 저장
    stack<pii> originalPos;  // 원래 ㅁㅊ 아두이노 위치
    stack<pii> updatePos;    // 업데이트된 아두이노 위치
    stack<pii> boom;         // 중복된 아두이노 폭팔

    int m = position[i] - '0' - 1;  // ㅈㅅ가 움직이려는 방향

    // board에서 ㅈㅅ, ㅁㅊ 아두이노의 위치를 저장
    for (int ii = 0; ii < r; ii++) {
      for (int jj = 0; jj < c; jj++) {
        if (board[ii][jj] == 'I') {
          Ix = ii;
          Iy = jj;
        }

        if (board[ii][jj] == 'R') q.push({ii, jj});
      }
    }

    // ㅈㅅ가 움직이는 위치 업데이트(1번 조건)
    int mx = Ix + dx[m];
    int my = Iy + dy[m];

    // ㅈㅅ의 움직인 위치에 ㅁㅊ 아두이노가 있는 경우 종료 (2번 조건)
    if (board[mx][my] == 'R') {
      cout << "kraj " << i + 1;
      return 0;
    }

    board[Ix][Iy] = '.';  // ㅈㅅ 원래 위치 '.'로 바꿈
    board[mx][my] = 'I';  // ㅈㅅ 위치 업데이트

    //  ㅁㅊ 아두이노 이동시킴
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      int minIndex = 9999999;
      int x, y;

      for (int dir = 0; dir < 9; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        int index = abs(mx - nx) + abs(my - ny);
        if (minIndex >= index) {
          minIndex = index;

          // ㅈㅅ의 위치와 가장 가까워 지는 방향으로 이동할때 그 위치 값을 저장(3번 조건)
          x = nx;
          y = ny;
        }
      }

      // ㅁㅊ 아두이노 위치와 ㅈㅅ의 위치가 같은 경우 종료(4번 조건)
      if (board[x][y] == 'I') {
        cout << "kraj " << i + 1;
        return 0;
      }

      originalPos.push({cur.X, cur.Y});  //  ㅁㅊ 아두이노의 원래 위치를 저장
      updatePos.push({x, y});            // ㅁㅊ 아두이노가 ㅈㅅ의 위치와 가장 가까워 지는 방향으로 이동할때 그 위치 저장
    }

    while (!originalPos.empty()) {
      auto cur = originalPos.top();
      originalPos.pop();

      board[cur.X][cur.Y] = '.';  // 기존의 아두이노 위치 수정
    }

    while (!updatePos.empty()) {
      auto cur = updatePos.top();
      updatePos.pop();

      // ㅁㅊ 아두이노가 중복된 경우  boom에 넣어줌(5번 조건)
      if (board[cur.X][cur.Y] == 'R') {
        boom.push({cur.X, cur.Y});
        continue;
      }

      board[cur.X][cur.Y] = 'R';  // 업데이트 된 아두이노 위치 표시
    }

    while (!boom.empty()) {
      auto cur = boom.top();
      boom.pop();

      board[cur.X][cur.Y] = '.';
    }
  }

  for (int i = 0; i < r; i++) cout << board[i] << '\n';
  return 0;
}