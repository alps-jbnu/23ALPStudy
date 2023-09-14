#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int m, n, arr[1000005];

bool solve(int mid){
    int cnt = 0;
    for(int i = 0;i<n;i++) cnt += arr[i]/mid;
    if(cnt>=m) return true;
    else return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 0;i<n;i++) cin >> arr[i];
  ll st = 0;
  ll en = 0x7fffffff;
  while(st<en){
    ll mid = (st+en+1)/2;
    if(solve(mid)) st = mid;
    else en = mid -1;
  }
  cout << st;
}
