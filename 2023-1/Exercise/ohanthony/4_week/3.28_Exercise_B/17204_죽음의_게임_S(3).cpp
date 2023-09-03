#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n, k;
int result;

int arr[155];

vector<bool> vis(160, false);  // 벡터의 크기 160, false 값으로 초기화

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int index = 0;
  vis[0] = true;  // vector 선언만 하고 배열 크기를 설정 안한 상태에서 다음과 같은 식 쓸 경우 없는 [0]에 접근 하는 것이므로 오류 발생

  while (vis[index]) {
    result++;
    index = arr[index];

    if (vis[index]) break;  // 한바퀴 돌았을 경우 종료

    vis[index] = true;
    if (index == k) {
      cout << result;
      return 0;
    }
  }

  // 한바퀴 돌았는데도 target 값 못찾을 경우 -1 출력
  cout << -1;
  return 0;
}