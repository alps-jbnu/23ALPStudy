#include <bits/stdc++.h>
using namespace std;

int n, arr[502][502];
int sum[502][502];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<i+1;j++){
      cin >> arr[i][j];
    }
  }
  for(int i = n-1;i>=0;i--){
    for(int j = 0;j<=i;j++){
      if(i == n-1) sum[i][j] = arr[i][j];
      else sum[i][j] = arr[i][j] + max(sum[i+1][j],sum[i+1][j+1]);
    }
  }
  cout << sum[0][0];
}
