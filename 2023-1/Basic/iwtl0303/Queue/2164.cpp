#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> Q;
  int N,num;
  cin >> N;
  for (int i = 1; i <=N; i++){
    Q.push(i);
  }
  while(Q.size()!=1){
    Q.pop();
    if(Q.size()!=1){
      num=Q.front();
      Q.push(num);
      Q.pop();
    }
    else break;
  }
  cout << Q.front() ;
  return 0;
}