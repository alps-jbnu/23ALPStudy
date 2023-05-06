#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N, L;
int board[105][105];
int result;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  // 행 검사
  for (int i = 0; i < N; i++) {
    int len = 1;  // 현재까지 연속된 같은 기둥의 수
    bool isRoad = true;
    for (int j = 0; j < N - 1; j++) {
      if (abs(board[i][j] - board[i][j + 1]) > 1) {  // 높이 차이가 1보다 클 경우 신경 x
        isRoad = false;
        break;
      }

      // 높이 같은 경우 연속된 같은 기둥의 수
      if (board[i][j] == board[i][j + 1]) len++;

      // 현재가 다음 기둥보다 클 경우
      else if (board[i][j] - board[i][j + 1] == 1) {
        if (len < 0)
          isRoad = false;
        else
          len = 1 - L;
      }

      // 현재가 다음 기둥보다 작을 경우
      else if (board[i][j] - board[i][j + 1] == -1) {
        if (len >= L)
          len = 1;
        else
          isRoad = false;
      }
    }

    if (isRoad && len >= 0) result++;
  }

  // 열 검사
  for (int i = 0; i < N; i++) {
    int len = 1;  // 현재까지 연속된 같은 기둥의 수
    bool isRoad = true;
    for (int j = 0; j < N - 1; j++) {
      if (abs(board[j][i] - board[j + 1][i]) > 1) {  // 높이 차이가 1보다 클 경우 신경 x
        isRoad = false;
        break;
      }

      // 높이 같은 경우 연속된 같은 기둥의 수
      if (board[j][i] == board[j + 1][i]) len++;

      // 현재가 다음 기둥보다 클 경우
      else if (board[j][i] - board[j + 1][i] == 1) {
        if (len < 0)
          isRoad = false;
        else
          len = 1 - L;
      }

      // 현재가 다음 기둥보다 작을 경우
      else if (board[j][i] - board[j + 1][i] == -1) {
        if (len >= L)
          len = 1;
        else
          isRoad = false;
      }
    }

    if (isRoad && len >= 0) result++;
  }

  cout << result;
  return 0;
}
