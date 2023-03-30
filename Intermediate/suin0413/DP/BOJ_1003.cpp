#include <bits/stdc++.h>
using namespace std;

int t;
vector<pair<int, int>> d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  d.push_back({1, 0});
  d.push_back({0, 1});
  for(int i = 2;i<42;i++){
    int t1 = d[i-1].first + d[i-2].first;
    int t2 = d[i-1].second + d[i-2].second;
    d.push_back({t1, t2});
  }
  while(t--){
    int n;
    cin >> n;
    cout << d[n].first << " " << d[n].second << "\n";
  }
}
