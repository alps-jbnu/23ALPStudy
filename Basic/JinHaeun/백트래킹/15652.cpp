#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool used[10];

void func(int k){ 
  if(k == m){ 
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; 
    cout << '\n';
    return;
  }

  int st = 1; // 시작지점
  if(k != 0) //0아닐떄
    st = arr[k-1]; //내림차순안되게할라고
  
  for(int i = st; i <= n; i++){
    arr[k] = i; 
    func(k+1); 
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}
