#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a[105];
bool power[105];
int n, k;
int ans;
int cnt;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> a[i];
  
  for (int i = 1; i <= k; i++){
    int cur = a[i];
    if (power[cur]) continue;
    if (cnt < n) {
      power[cur] = true;
      cnt++;
    }else{
      vector<pair<int, int>> idx;
      for (int x = 0; x < k; x++){
        if (!power[x]) continue;
        bool vis = false;
        for (int y = i; y < k; y++){
          if (a[y] == x) {
            idx.push_back({y, x});
            vis = true;
            break;
          }
        }
        if (!vis) idx.push_back({k + 1, x});
      }
      sort(idx.begin(), idx.end(), greater<pair<int, int>>());
      int target = idx[0].Y;
      power[target] = false; ans++;
      power[cur] = true;
    }
  }
  cout << ans;
}