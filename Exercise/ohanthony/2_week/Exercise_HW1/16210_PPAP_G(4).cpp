#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define pii pair<int, int>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  stack<char> s;
  string sentecne, temp = "";
  cin >> sentecne;

  int len = sentecne.length();

  for (int i = 0; i < len; i++) {
    if (sentecne[i] == 'P') {
      s.push(sentecne[i]);
    } else {
      if (s.size() >= 2 && sentecne[i + 1] == 'P') {
        s.pop();
        i++;
      } else {
        cout << "NP";
        return 0;
      }
    }
  }

  if (s.size() == 1) {
    cout << "PPAP";
  } else {
    cout << "NP";
  }

  return 0;
}