#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m, k;
vector<pair<int,int>> adj[1005]; // {비용, 정점 번호}
bool chk[1005];
int p[1005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0;i<k;i++) cin >> p[i];
  for(int i = 0;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  int ans = 0;
  int cnt = 0; // cnt = n - k까지
  priority_queue< tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq;
  for(int i = 0;i<k;i++){
    int cur = p[i];
    chk[cur] = 1;
    for(auto nxt : adj[cur])
      pq.push({nxt.X, cur, nxt.Y});
  }

  while(cnt < n-k){
    int c, a, b;
    tie(c,a,b) = pq.top(); pq.pop();
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
