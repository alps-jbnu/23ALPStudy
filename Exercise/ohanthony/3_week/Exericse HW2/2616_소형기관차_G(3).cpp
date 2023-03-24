#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n;
int train[50005];
int dp[5][50005];  // x번째 소형 기차인 경우 y번째 까지 객차를 끌고 데려갈 수 있는 사람수 저장
// x: 소형 기차 번호, y: 객차 번호

int c;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;

    train[i] = train[i - 1] + num;  // 각 칸의 누적 승객 수를 구함
  }
  cin >> c;

  for (int i = 1; i <= 3; i++) {
    for (int j = i * c; j <= n; j++) {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - c] + (train[j] - train[j - c]));
    }
  }

  cout << dp[3][n];
  return 0;
}