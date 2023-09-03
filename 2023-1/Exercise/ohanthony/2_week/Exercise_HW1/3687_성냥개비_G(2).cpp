#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int k, n;
ll dp_m[105];
int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};

void MIN() {
  for (int i = 1; i <= 9; i++) {
    dp_m[i] = num[i];
  }

  dp_m[6] = 6;

  for (int i = 9; i <= 100; i++) {
    dp_m[i] = dp_m[i - 2] * 10 + num[2];

    for (int j = 3; j < 8; j++) {
      dp_m[i] = min(dp_m[i], dp_m[i - j] * 10 + num[j]);
    }
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

  cin >> k;

  MIN();

  while (k--) {
    cin >> n;

    cout << dp_m[n] << " ";

    string MAX = "";
    while (n) {
      if (n % 2 != 0) {
        cout << 7;
        n -= 3;
      } else {
        cout << 1;
        n -= 2;
      }
    }

    cout << "\n";
  }

  return 0;
}

/*
(가장 작은 수)
- 각 자릿수에 성냥을 할당하는 모든 경우 고려


(가장 큰 수를 만드는 경우)
- 자릿수를 늘려야함
- 1만 사용하는 것이 가장 큰 수를 만들 수 있음

- even: 성냥을 가장 조금 사용하는 '1'만을 이용하는 것
- odd: 1 다음으로 가장 적은 성냥인 '7'을 이용

*/
