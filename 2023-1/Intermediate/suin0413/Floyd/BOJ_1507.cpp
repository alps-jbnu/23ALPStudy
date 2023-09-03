#include <bits/stdc++.h>
using namespace std;

int d[25][25];
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++) cin >> d[i][j];

  int sum = 0;
  for(int i = 1;i<=n;i++)
    for(int j = i+1;j<=n;j++)
      sum += d[i][j];

  for(int i = 1;i<=n;i++)
    for(int j = i+1;j<=n;j++)
      for(int k = 1;k<=n;k++){
        if(k == i || k == j) continue; // d[i][j] == d[i][i] + d[i][j]
        else if(d[i][j] == d[i][k] + d[k][j]){ // 돌아가는 게 더 빠른 경우
            // 연결을 끊음
            sum -= d[i][j];
            break;
        }
        else if(d[i][j] < d[i][k] + d[k][j]) continue; // 더 빠른 경로가 있는 경우
        else { // 불가능한 경우
            cout << "-1";
            return 0;
        }
      }  

  cout << sum;
  // 플로이드를 역으로 이용
}
