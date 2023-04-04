#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int N;
int a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> a[i];
  int ans1 = 1e9+1;
  int ans2 = 1e9+1;

  for(int i = 0; i < N; i++){
    int idx = lower_bound(a, a+N, -a[i]) - a;

    if(idx+1 < N && i != idx+1 && abs(a[i] + a[idx+1]) < abs(ans1 + ans2)){
      ans1 = a[i];
      ans2 = a[idx+1];
    }
    if(idx < N && i != idx && abs(a[i] + a[idx]) < abs(ans1 + ans2)){
      ans1 = a[i];
      ans2 = a[idx];
    }
    if(idx != 0 && i != idx-1 && abs(a[i] + a[idx-1]) < abs(ans1 + ans2)){
      ans1 = a[i];
      ans2 = a[idx-1];
    }
  }
  if(ans1 > ans2) swap(ans1, ans2);
  cout << ans1 << ' ' << ans2;
}