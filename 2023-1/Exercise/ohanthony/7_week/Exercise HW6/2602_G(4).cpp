#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

string magic, devil, angel;
int result;

int dev_dp[105][25];
int ang_dp[105][25];

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> magic >> devil >> angel;

  int len = devil.size();

  for (int i = 0; i < len; i++) {
    if (magic[0] == devil[i]) dev_dp[i][0] = 1;
    if (magic[0] == angel[i]) ang_dp[i][0] = 1;
  }

  for (int i = 0; i < len; i++) {
    for (int j = 1; j < magic.size(); j++) {
      if (magic[j] == devil[i]) {
        int n = 0;
        for (int k = 0; k < i; k++) {
          if (ang_dp[k][j - 1] != 0) n += ang_dp[k][j - 1];
          dev_dp[i][j] = n;
        }
      }

      if (magic[j] == angel[i]) {
        int n = 0;
        for (int k = 0; k < i; k++) {
          if (dev_dp[k][j - 1] != 0) n += dev_dp[k][j - 1];
          ang_dp[i][j] = n;
        }
      }
    }
  }

  for (int i = 0; i < len; i++) {
    result += ang_dp[i][magic.size() - 1];
    result += dev_dp[i][magic.size() - 1];
  }

  cout << result;

  return 0;
}
