#include <bits/stdc++.h>
using namespace std;

int n;
int a[505][505], d[505][505]; //합 넣을 배열, 원래 삼각형 넣을 배열
int sum;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      cin >> a[i][j];
  d[1][1] = a[1][1];
  for(int i = 2; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j]; 
      //한 라인 위에 왼쪽 오른쪽 비교해서 더 큰 값을 현재값과 더해서 넣기
  cout << *max_element(d[n] + 1, d[n] + n + 1);
  //d[n]값이 다 더해진 값이니까 마지막 줄에서 최대값 찾기
}