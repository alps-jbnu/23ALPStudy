#include <bits/stdc++.h>
using namespace std;

int n, cur, ans, minSum, maxSum;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++) { // 누적합
    int tmp;
    cin >> tmp;
    if (tmp == 1) cur++;
    else cur--;
    
    // 최대 깨달음
    ans = max(ans, abs(cur - minSum));
    ans = max(ans, abs(cur - maxSum));

    // 구간합 최댓값, 최솟값 찾기
    minSum = min(minSum, cur);
    maxSum = max(maxSum, cur);
  }

  cout << ans;
}
