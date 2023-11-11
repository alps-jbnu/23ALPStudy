#include <bits/stdc++.h>
using namespace std;

int n, cur;
string tmp, pattern;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> pattern;
  while (n--) {
    bool correct = true;
    cin >> tmp;
    for (int i = 0; i < pattern.size(); i++) {
      if (pattern[i] == '*') break;
      if (pattern[i] != tmp[i]) {
        correct = false;
        break;
      }
      cur = i;
    }
    for (int i = 1; i < pattern.size(); i++) {
      if (tmp.size() - i == cur - 1) {
        correct = false;
        break;
        }
      if (pattern[pattern.size() - i] == '*') break;
      if (pattern[pattern.size() - i] != tmp[tmp.size() - i]) {
        correct = false;
        break;
      }
    }
    if (correct == true) cout << "DA\n";
    else cout << "NE\n";
  }
}
