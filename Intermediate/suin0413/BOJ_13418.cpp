#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m;
vector<pair<int,int>> adj[1005]; // {비용, 정점 번호}
int chk[1005];
int mx(){
  fill(chk, chk+n, 0);
  int cnt = 0; 
  int ans = 0;
  priority_queue< tuple<int,int,int>,
                  vector<tuple<int,int,int>>,
                  less<tuple<int,int,int>> > pq;

  chk[0] = 1;
  for(auto nxt : adj[0])
    pq.push({nxt.X, 1, nxt.Y});

  while(cnt < n){
    int cost, a, b;
    tie(cost, a, b) = pq.top(); pq.pop();
    if(chk[b]) continue;
    ans += cost;
    chk[b] = 1;
    cnt++;
    for(auto nxt : adj[b]){
      if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }
  return ans;
}

int mn(){
  fill(chk, chk+n, 0);
  int cnt = 0; 
  int ans = 0;
  priority_queue< tuple<int,int,int>,
                  vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq;

  chk[0] = 1;
  for(auto nxt : adj[0])
    pq.push({nxt.X, 1, nxt.Y});

  while(cnt < n){
    int cost, a, b;
    tie(cost, a, b) = pq.top(); pq.pop();
    if(chk[b]) continue;
    ans += cost;
    chk[b] = 1;
    cnt++;
    for(auto nxt : adj[b]){
      if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  m++;
  while(m--){
    int a,b; bool c;
    cin >> a >> b >> c;
    adj[a].push_back({!c,b});
    adj[b].push_back({!c,a});
  }
  int ans = 0;
  ans += mx();
  ans -= mn();
  cout << ans;
}
// 
