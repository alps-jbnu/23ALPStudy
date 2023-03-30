#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int n, m, l;
/*
- m: 사대의 수
- n: 동물의 수
- l: 사정거리
*/

int x, y, result;

vector<int> pos;     // 사대의 위치
vector<pii> animal;  // 동물의 위치

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> m >> n >> l;
  for (int i = 0; i < m; i++) {
    cin >> x;
    pos.push_back(x);
  }

  // x, y 좌표가 주어진다고 해서 2차원으로 생각할 필요 없이 사대를 일직선으로 펼쳐놓고 그걸 가지고 이분탐색을 진행
  sort(pos.begin(), pos.end());

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    animal.push_back({x, y});
  }

  for (int i = 0; i < n; i++) {
    int st = 0;
    int en = m - 1;

    while (st <= en) {
      int mid = (st + en) / 2;
      int hunt = abs(pos[mid] - animal[i].X) + animal[i].Y;

      if (l >= hunt) {
        result++;
        break;
      } else {
        if (pos[mid] > animal[i].X)
          en = mid - 1;
        else
          st = mid + 1;
      }
    }
  }

  cout << result;
  return 0;
}