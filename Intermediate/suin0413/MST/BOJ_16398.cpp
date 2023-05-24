#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n;
vector<pair<int,int>> adj[1005]; // {비용, 정점 번호}
bool chk[1005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++){
      int c; cin >> c;
      if(i == j) continue;
      adj[i].push_back({c,j});
    }
  
  int cnt = 0;
  long long ans = 0;
  priority_queue< tuple<int,int,int>,
                  vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq;

  chk[0] = 1;
  for(auto nxt : adj[0])
    pq.push({nxt.X, 1, nxt.Y});

  while(cnt < n - 1){
    int c, a, b;
    tie(c, a, b) = pq.top(); pq.pop();
    if(chk[b]) continue;
    ans += c;
    chk[b] = 1;
    cnt++;
    for(auto nxt : adj[b]){
      if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }
  cout << ans;
}

