#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int N;
ll sol[5000];
ll ans[3] = {0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> sol[i];
  sort(sol, sol+N);

  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      int idx = lower_bound(sol, sol+N, -sol[i] - sol[j]) - sol;

      for(int k = -2; k <= 2; k++){
        if(idx+k == i || idx+k == j) continue;
        if(idx+k < 0 || idx+k >= N) continue;
        if(abs(ans[0] + ans[1] + ans[2]) > abs(sol[i] + sol[j] + sol[idx+k]))
          tie(ans[0], ans[1], ans[2]) = {sol[i], sol[j], sol[idx+k]};   
      }
    }
  }
  sort(ans, ans+3);
  cout << ans[0] << " " << ans[1] << " " << ans[2];
}