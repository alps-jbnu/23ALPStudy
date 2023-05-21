#include <bits/stdc++.h>        
using namespace std;

int n,m;
int arr[10];
int ans[10];
bool isused[10];
void func(int k){
  if(k == m){
    for(int i=0;i<m;i++){
      cout << ans[i] << ' ';
    }
    cout<<"\n";
    return;
  }
  for(int i=0;i<n;i++){
    if(k != 0){
      if(ans[k-1] > arr[i]) continue;
    }
    if(!isused[i]){
      ans[k]=arr[i];
      isused[i]=true;
      func(k+1);
      isused[i]=false;
    }
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i=0;i<n;i++) cin >> arr[i];
  sort(arr,arr+n);
  func(0);
}
