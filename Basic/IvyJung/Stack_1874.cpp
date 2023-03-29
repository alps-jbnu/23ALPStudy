#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  int cnt = 1;
  string ans;
  
  while (n--) {
    int t;
    cin >> t;
    while (cnt <= t) {
      s.push(cnt++);
      ans += "+\n";
    }
    if (s.top() != t) {
      cout << "NO\n";
      return 0;
    }
    s.pop();
    ans += "-\n";
  }
  cout << ans;
}