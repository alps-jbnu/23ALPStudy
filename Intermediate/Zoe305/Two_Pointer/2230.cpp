#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[100005];
int mn = 0x7fffffff;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> a[i];
  sort(a, a+N);

  int en = 0;
  for(int st = 0; st < N; st++){
    while(en < N && a[en] - a[st] < M) en++;
    if(en == N) break;
    mn = min(mn, a[en] - a[st]);
  }
  cout << mn;
}