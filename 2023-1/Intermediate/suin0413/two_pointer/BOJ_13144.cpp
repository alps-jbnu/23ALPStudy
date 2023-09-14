#include <bits/stdc++.h>
using namespace std;

int n, a[100002];
bool check[100002];
long long ans = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  check[a[0]] = 1;
  int en = 0;
  for(int st = 0;st<n;st++){
    while(check[a[en+1]] != 1 && en < n-1) {
        en++;
        check[a[en]] = 1;
    }
    ans += (en-st+1);
    check[a[st]] = 0;
  }
  cout << ans;
}
