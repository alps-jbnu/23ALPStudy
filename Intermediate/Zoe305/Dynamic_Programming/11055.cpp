#include <bits/stdc++.h>
using namespace std;

int n;
int a[1004], dp[1004];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = a[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
  
  cout << *max_element(dp, dp + n);
}