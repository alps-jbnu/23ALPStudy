#include <bits/stdc++.h>
using namespace std;

int n;
int a[100003], d[100003];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    d[i] = a[i];
  }

  for(int i = 1; i <= n; ++i)
    d[i] = max(d[i], d[i-1] + a[i]);
  cout << *max_element(d + 1, d + n + 1);
}//구간합 구하기라는 문제랑 비슷했던 것 같음