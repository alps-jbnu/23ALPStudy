#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++){
    int a, b;
    cin >> a >> b;
    v.push_back({a,b});
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  int st = v[0].first; 
  int ed = v[0].second;
  for(int i = 1;i<n;i++){
    if(ed>=v[i].first){
        ed = max(ed, v[i].second);
    }
    else {
        ans += ed - st;
        st = v[i].first;
        ed = v[i].second;
    }
  }    
  ans += ed - st;
  cout << ans;
}
