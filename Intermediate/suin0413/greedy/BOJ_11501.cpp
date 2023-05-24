#include <bits/stdc++.h>
using namespace std;

int n, arr[1000002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0;i<n;i++) cin >> arr[i];
    long long ans = 0;
    int max = arr[n-1];
    for(int i = n-2;i>=0;i--){
        if(max<arr[i]) max = arr[i];
        else ans += max - arr[i];
    }
    cout << ans << "\n";
  }  
}
