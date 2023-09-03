#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int tempSum[200005][26];

string S;
int q;
char a;
int l, r;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> S >> q;

  for (int i = 0; i < S.size(); i++) {
    if (i != 0) {  // 이전 값들의 합
      for (int j = 0; j < 26; j++) tempSum[i][j] = tempSum[i - 1][j];
    }

    int n = S[i] - 'a';
    tempSum[i][n]++;
  }

  while (q--) {
    int count = 0;
    cin >> a >> l >> r;

    int n = a - 'a';

    if (l > 0) {
      int x = tempSum[l - 1][n];
      cout << tempSum[r][n] - x << '\n';
    } else
      cout << tempSum[r][n] << '\n';
  }

  return 0;
}
