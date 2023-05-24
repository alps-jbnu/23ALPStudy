#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr[1][1] = 1; 
  arr[2][0] = 1; 
  for(int i = 3;i<=n;i++){
    arr[i][0] = arr[i-1][0] + arr[i-1][1];
    arr[i][1] = arr[i-1][0];
  }
  cout << arr[n][0] + arr[n][1]; 
}
