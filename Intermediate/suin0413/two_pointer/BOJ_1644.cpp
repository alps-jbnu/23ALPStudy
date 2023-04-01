#include <bits/stdc++.h>
using namespace std;

const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> primes;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i=2; i*i<MXN; i++){
    if (!seive[i]) continue;
    for (int j = i * i; j < MXN; j += i) 
      seive[j] = false;
  }
  for (int i = 2; i < MXN; i++) if (seive[i]) primes.push_back(i);
  primes.push_back(0);

  int n, st = 0, en = 1, ans = 0, sum = primes[0];
  cin >> n;
  while (1) {
    if (sum == n) ans++;
    if (sum <= n) sum += primes[en++];
    if (sum > n) sum -= primes[st++];
    if (en == int(primes.size())) break;
  }
  cout << ans;
}
