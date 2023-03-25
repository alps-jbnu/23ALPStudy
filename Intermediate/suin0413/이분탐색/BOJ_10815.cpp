#include <bits/stdc++.h>
using namespace std;

int n, m, arr[500005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << binary_search(arr,arr+n,t) << " ";
  }
}
