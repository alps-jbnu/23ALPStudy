#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,k,a,b,cnt=0;
  int arr [2][6]={0,};
  cin>>n>>k;
  for(int i=0; i<n;i++){
    cin>>a>>b;
    arr[a][b-1]++;
  }
  for(int i=0; i<2;i++){
    for(int j=0; j<6 ; j++){
      cnt += arr[i][j]/k;
      if (arr[i][j]%k !=0) cnt++;
    }
  }
  cout << cnt;
}
