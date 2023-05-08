#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, x, y;
int result;
stack<int> s;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;

    while (!s.empty() && s.top() >= y) {
      if (s.top() != y) result++;
      s.pop();
    }
    s.push(y);
  }

  // 스택에 남아있는 건물 세기 위해
  while (!s.empty()) {
    if (s.top() != 0) result++;
    s.pop();
  }

  cout << result;
  return 0;
}
