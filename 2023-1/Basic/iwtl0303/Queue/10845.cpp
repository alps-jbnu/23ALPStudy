#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> q;
  int n,num;
  string op;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> op;
    if (op == "push") {
      cin >> num;
      q.push(num);
    }
    else if (op == "pop") {
      if (q.empty()) cout << -1 << "\n";
      else {
        num = q.front();
        q.pop();
        cout << num << "\n";
      }
    }
    else if (op == "size") cout << q.size() << "\n";
    else if ( op == "empty") {
      if (q.empty()) cout << 1 << "\n";
      else cout << 0 << "\n";
    }
    else if (op == "front") {
      if (q.empty()) cout << -1 << "\n";
      else cout << q.front() << "\n";
    }
    else {
      if (q.empty()) cout << -1 << "\n";
      else cout << q.back() << "\n";
    }
  }
  
}