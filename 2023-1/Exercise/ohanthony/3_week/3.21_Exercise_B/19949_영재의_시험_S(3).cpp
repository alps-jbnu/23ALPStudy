#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int test[10];
int myAns[10];
ll result;

void func(int k) {
  if (k == 10) {
    int sol = 0;
    for (int i = 0; i < 10; i++) {
      if (myAns[i] == test[i]) sol++;
    }

    // 맞힌 문제가 5개 이상일 경우
    if (sol >= 5) result++;
    return;
  }

  for (int i = 1; i <= 5; i++) {
    // 3개 연속된 문제가 같을 경우
    if (k > 1 && myAns[k - 2] == i && myAns[k - 1] == i) continue;

    myAns[k] = i;
    func(k + 1);
    myAns[k] = 0;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 10; i++) cin >> test[i];

  func(0);

  cout << result;

  return 0;
}