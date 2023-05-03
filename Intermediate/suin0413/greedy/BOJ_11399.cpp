#include <bits/stdc++.h>
using namespace std;

int n, p[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++) cin >> p[i];
  sort(p,p+n);
  int sum = 0;
  for(int i = 0;i<n;i++){
    sum += p[i];
    p[i] = sum;
  }
  int ans = 0;
  for(int i = 0;i<n;i++) ans += p[i];
  cout << ans;
}
