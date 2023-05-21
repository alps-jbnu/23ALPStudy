#include <bits/stdc++.h>        
using namespace std;

int n;
char arr[65][65];

bool check(int x, int y, int n){
  for (int i=x;i<x+n; i++)
  for(int j=y; j<y+n; j++){
    if(arr[i][j]!=arr[x][y]) return false;
  }
  return true;
}
void func(int x, int y, int n){
  if(check(x, y, n)){
    cout << arr[x][y];
  }
  else{
    cout<<"(";
    func(x,y,n/2);
    func(x,y+n/2,n/2);
    func(x+n/2,y,n/2);
    func(x+n/2,y+n/2,n/2);
    cout<<")";
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++)
  for(int j=0;j<n;j++)
   cin >> arr[i][j];
   func(0,0,n);
}
