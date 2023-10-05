#include <bits/stdc++.h>
using namespace std;

int n, a, b, q, t, k;
vector<int> adj[100002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> t >> k;
    if (t == 1) {
      if (adj[k].size() <= 1) cout << "no\n";
      else cout << "yes\n";
    }
    else cout << "yes\n";
  }
}
