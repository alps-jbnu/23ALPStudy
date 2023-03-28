#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N, M, Q;
/*
- N: 통신탑의 개수
- M: 통신탑 사이의 연결의 개수
- Q: 통신망 연결 분할 횟수
*/

vector<pii> com(1);
vector<int> remo;  // 끊는 지점
bool vis[100005];

ll uni_find[100005];

ll result;

int FIND(int k) {
  if (uni_find[k] < 0) return k;

  return uni_find[k] = FIND(uni_find[k]);
}

void UNION(int x, int y) {
  x = FIND(x);
  y = FIND(y);

  if (x == y) return;

  if (uni_find[x] <= uni_find[y]) {
    uni_find[x] += uni_find[y];
    uni_find[y] = x;
  } else {
    uni_find[y] += uni_find[x];
    uni_find[x] = y;
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

  memset(uni_find, -1, sizeof(uni_find));

  cin >> N >> M >> Q;
  for (int i = 1; i <= M; i++) {
    int x, y;
    cin >> x >> y;
    com.push_back({x, y});
  }

  while (Q--) {
    int x;
    cin >> x;
    vis[x] = true;
    remo.push_back(x);  // x번째 요소를 끓음
  }

  for (int i = 1; i <= M; i++) {
    if (!vis[i]) UNION(com[i].X, com[i].Y);
  }

  for (int i = remo.size() - 1; i >= 0; i--) {
    int x = com[remo[i]].X;
    int y = com[remo[i]].Y;

    if (FIND(x) != FIND(y)) {
      result += (uni_find[FIND(x)] * uni_find[FIND(y)]);
    }
    UNION(x, y);
  }

  cout << result;
  return 0;
}
