#include <bits/stdc++.h>
using namespace std;

int n, a[4002], b[4002], c[4002], d[4002];
vector<int> v1;
vector<int> v2;

int main(void) {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        v1.push_back(a[i]+b[j]);
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        v2.push_back(c[i]+d[j]);
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  long long ans = 0;
  for(int i = 0;i<v1.size();i++){
    auto ub = upper_bound(v2.begin(), v2.end(), -v1[i]);
    auto lb = lower_bound(v2.begin(), v2.end(), -v1[i]);
    ans += ub - lb;
  }
  cout << ans;
}
