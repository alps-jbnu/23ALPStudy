#include <bits/stdc++.h>
using namespace std;

int N, C;
int x[200002];

bool program(int len){
  int idx = 0, cnt = 0;
    while(idx != N) {
      idx = lower_bound(x + idx, x + N, x[idx] + len) - x;
      cnt++;
    }
  return cnt >= C;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> C;
  for(int i = 0; i < N; i++) cin >> x[i];
  sort(x, x + N);

  int st = 1, en = 1000000000;
  int mid;
  while(st < en) {
    mid = (st + en + 1)/2;
    if(program(mid)) st = mid;
    else en = mid - 1;
  }

  cout << st;
}