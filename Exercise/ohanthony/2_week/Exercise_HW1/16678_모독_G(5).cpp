#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, temp = 1;
ll result;
int arr[100005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];

  sort(arr, arr + n + 1);

  // 한번의 defile을 할려면 1, 2, 3, ..., n의 순서가 되어야 한다.
  for (int i = 1; i <= n; i++) {
    if (arr[i] >= temp) {
      result += arr[i] - temp;
      temp++;
    }
  }

  cout << result;
  return 0;
}
