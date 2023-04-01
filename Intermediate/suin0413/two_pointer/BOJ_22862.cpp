#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
int a[1000002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0;i<n;i++) {
    int t;
    cin >> t;
    a[i] = t%2;
  }
  int en = 0;
  int sum = a[0];
  for(int st = 0;st<n;st++){
    while(en<n-1 && sum <= k) {
        if(sum == k && a[en+1] == 1) break;
        en++;
        sum += a[en];
    }
    ans = max(ans, en-st+1-sum);
    sum -= a[st];
  }
  cout << ans;
}
