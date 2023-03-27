#include <bits/stdc++.h>

using namespace std;

int N, S, sum;
int a[100005];
int mn = 0x7fffffff;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> S;
  for(int i = 0; i < N; i++) cin >> a[i];
  sum = a[0];
  int en = 0;
  for(int st = 0; st < N; st++){
    while(en < N && sum < S){
      en++;
      if(en != N) sum += a[en];
    }
    if(en == N) break;
    mn = min(mn, en - st + 1);
    sum -= a[st];
  }
  if(mn == 0x7fffffff) mn = 0;
  cout << mn;
}