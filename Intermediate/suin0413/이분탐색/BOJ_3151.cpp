#include <bits/stdc++.h>
using namespace std;

int n, arr[10003];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++) cin >> arr[i];
  sort(arr, arr+n);
  long long ans = 0; 
  for(int i = 0;i<n-1;i++){
    for(int j = i+1;j<n;j++){
      auto ub = upper_bound(arr+j+1,arr+n,-arr[i]-arr[j]);
      auto lb = lower_bound(arr+j+1,arr+n,-arr[i]-arr[j]);
      ans += ub - lb;
    }
  }
  cout << ans;
}
