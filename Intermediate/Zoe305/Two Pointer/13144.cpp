#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
vector<bool> check(100002);

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];

  long long ans = 0;
  check[arr[0]] = 1;
  int en = 0;

  for(int st = 0; st < N; st++){
    while (en < N-1 && !check[arr[en+1]]){
      en++;
      check[arr[en]] = 1;
    }
    ans += (en-st+1);
    check[arr[st]] = 0;
  }
  cout << ans;
}