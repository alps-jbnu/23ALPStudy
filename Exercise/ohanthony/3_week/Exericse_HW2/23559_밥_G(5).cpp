#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, x, result;
int a, b;

vector<pii> v;

// 5000원 짜리 메뉴와 1000원 짜리 메뉴의 맛의 차이가 큰 날짜가 먼저오게 정렬
bool cmp(pair<int, int> c, pair<int, int> d) { return c.X - c.Y > d.X - d.Y; }

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});

    result += b;  // 우선 최소 비용을 만들고 시작
  }

  sort(v.begin(), v.end(), cmp);

  int st = 1000 * n;

  for (int i = 0; i < n; i++) {
    if (v[i].X > v[i].Y) {
      st += 4000;  // 5000원 짜리와 1000원 짜리의 차이

      if (st > x) break;  // 수정한 금액이 한도보다 클 경우 넘어감
      result += (v[i].X - v[i].Y);
    }
  }

  cout << result;
  return 0;
}