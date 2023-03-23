#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, arr[1000005];

bool solve(ll mid)
{
    ll sum = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]>mid) sum += arr[i]-mid;
    }
    if(sum>=m) return true;
    else return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
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
