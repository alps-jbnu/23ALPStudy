#include <bits/stdc++.h>        
using namespace std;

int n;
int cnt;
bool isused1[40]; // 열을 검사 (왜 배열 크기가 40인지 물어보자)
bool isused2[40]; // '/'방향 대각선을 검사
bool isused3[40]; // '\'방향 대각선을 검사

void func(int cur){
  if(cur==n){
    cnt++;
    return;
  }
  for (int i=0; i<n; i++){
    if (isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]){
      continue;
    }
    isused1[i] = 1;
    isused2[i+cur] = 1;
    isused3[cur-i+n-1] = 1;
    func(cur+1);
    isused1[i] = 0;
    isused2[i+cur] = 0;
    isused3[cur-i+n-1] = 0;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  func(0);
  cout<<cnt;
}
