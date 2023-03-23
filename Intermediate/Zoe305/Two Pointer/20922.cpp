#include <bits/stdc++.h>

using namespace std;

int N, K, ans;
int cnt[100005];
int a[200005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> a[i];

  int en = 0;
  ++cnt[a[en]];
  for (int st = 0; st < N; ++st){

    while(en + 1 != N && cnt[a[en + 1]] < K){
      ++en;
      cnt[a[en]]++;
    }

    ans = max(ans, en - st + 1);
    cnt[a[st]]--;
  }
  cout << ans;
}