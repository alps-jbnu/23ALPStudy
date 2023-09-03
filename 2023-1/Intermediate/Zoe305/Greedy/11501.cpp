#include <bits/stdc++.h>
using namespace std;

int a[1000002];
int T;
long long ans;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int max_val = a[n-1];
    for(int i = n-2; i >= 0; i--) {
      if(a[i] > max_val) max_val = a[i];
      ans += max_val - a[i];
    }
    cout << ans << '\n';
  }
}

/*
거꾸로 돌면서 최대값을 구해 값을 더해준다.
*/