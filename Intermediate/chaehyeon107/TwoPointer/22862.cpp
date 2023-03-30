#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int arr[1000005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int cnt = 0; 
  if(arr[0] % 2 == 1) cnt++; //
  int en = 0;
  for(int st = 0; st < n; st++){
    while(en < n-1 && cnt + arr[en+1] % 2 <= k){
      en++;
      cnt += arr[en] % 2;
    }
    ans = max(ans, en - st + 1 - cnt);
    cnt -= arr[st] % 2;
  }
  cout << ans;
}
