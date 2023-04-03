#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n, m, result;
vector<int> parade(100005);
vector<int> temp(100005);

int a, b, k;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> parade[i];
  while (m--) {
    cin >> a >> b >> k;
    temp[a] += k;      // 1~a까지 누적합
    temp[b + 1] -= k;  // b + 1 번째 누적합
  }

  for (int i = 1; i <= n; i++) {
    result += temp[i];
    parade[i] += result;
    cout << parade[i] << ' ';
  }

  return 0;
}