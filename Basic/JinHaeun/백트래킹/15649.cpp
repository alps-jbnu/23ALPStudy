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

  for(int i = 1; i <= n; i++){
    if(!used[i]){ 
      arr[k] = i;
      used[i] = 1; 
      func(k+1); 
      used[i] = 0; 
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}
