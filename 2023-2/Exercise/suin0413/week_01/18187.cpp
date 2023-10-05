#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int d[101];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  d[1] = 2; a = 1;
  for (int i = 2; i <= n; i++) {
    if (i % 3 == 1) {
      d[i] = d[i - 1] + b + c + 1;
      a++;
    }
    else if (i % 3 == 2) {
      d[i] = d[i - 1] + a + c + 1;
      b++;
    }
    else {
      d[i] = d[i - 1] + a + b + 1;
      c++;
    }
  }
  cout << d[n];
}
