#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  // arr[k] = arr[k-1] + arr[k-2] * 2
  arr[1] = 1;
  arr[2] = 3;
  for(int i = 3; i<=n;i++){
    arr[i] = (arr[i-1] + arr[i-2] * 2) % 10007;
  }
  cout << arr[n];
}
