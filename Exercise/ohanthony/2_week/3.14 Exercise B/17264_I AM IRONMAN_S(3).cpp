#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, p, w, l, g;
/*
- n: 총 게임 횟수
- p: 플레이어 정보의 수

- w: 이긴 경우 흭득 점수
- l: 졌을때 떨어지는 점수
- g: 티어에 벗어나기 위한 점수
*/

map<string, int> player;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> p;
  cin >> w >> l >> g;
  for (int i = 0; i < p; i++) {
    string name, state;
    cin >> name >> state;

    if (state == "W") {
      player[name] = w;
    } else {
      player[name] = l;
    }
  }

  int targetScore = 0;

  while (n--) {
    string name;
    cin >> name;

    if (player[name]) {
      if (player[name] == w) {
        targetScore += w;
      } else {
        targetScore -= l;
      }
    } else {
      targetScore -= l;
    }

    if (targetScore < 0) {
      targetScore = 0;
    } else if (targetScore >= g) {
      cout << "I AM NOT IRONMAN!!";
      return 0;
    }
  }

  cout << "I AM IRONMAN!!";
  return 0;
}