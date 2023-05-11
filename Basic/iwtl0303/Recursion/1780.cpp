#include <bits/stdc++.h>        
using namespace std;

int n;
int arr[2190][2190];
int cnt[3];

bool check(int x, int y, int n){
  for (int i = x; i<x+n;i++){
    for (int j=y;j<y+n;j++)
      if (arr[x][y]!=arr[i][j])
      return false;
  }
  return true;
}
void func(int x, int y, int z){
  if(check(x,y,z)){
    cnt[arr[x][y]+1] +=1;
    return;
  }
  int n = z/3;
  for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
    func(x + i * n, y + j * n, n);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) 
    cin >> arr[i][j];
  func(0,0,n);
  for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
}
