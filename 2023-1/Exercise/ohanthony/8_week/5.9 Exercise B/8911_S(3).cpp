#include <bits/stdc++.h>
using namespace std;
#define ll long long  // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int t;
string order;

int main() {
#ifndef ONLINE_JUDGE
  freopen("C:/Users/vl619/Development/vsCode_C++/input.txt", "r", stdin);
  freopen("C:/Users/vl619/Development/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    int x = 0, y = 0;  // 시작점
    vector<int> xx;
    vector<int> yy;

    int Dir = 0;

    xx.push_back(x);
    yy.push_back(y);

    cin >> order;
    for (int i = 0; i < order.size(); i++) {
      if (order[i] == 'F') {
        if (Dir == 0)
          y++;
        else if (Dir == 1)
          x++;
        else if (Dir == 2)
          y--;
        else if (Dir == 3)
          x--;
      } else if (order[i] == 'B') {
        if (Dir == 0)
          y--;
        else if (Dir == 1)
          x--;
        else if (Dir == 2)
          y++;
        else if (Dir == 3)
          x++;
      } else if (order[i] == 'L') {
        if (Dir == 0)
          Dir = 3;
        else if (Dir == 1)
          Dir = 0;
        else if (Dir == 2)
          Dir = 1;
        else if (Dir == 3)
          Dir = 2;
      } else {  // R인 경우
        if (Dir == 0)
          Dir = 1;
        else if (Dir == 1)
          Dir = 2;
        else if (Dir == 2)
          Dir = 3;
        else if (Dir == 3)
          Dir = 0;
      }

      xx.push_back(x);
      yy.push_back(y);
    }

    sort(xx.begin(), xx.end());
    x = xx[order.size()] - xx[0];

    sort(yy.begin(), yy.end());
    y = yy[order.size()] - yy[0];

    cout << x * y << '\n';
  }
  return 0;
}