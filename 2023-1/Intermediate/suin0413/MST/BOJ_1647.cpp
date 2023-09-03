#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m, mx;
vector<pair<int,int>> adj[100005]; // {비용, 정점 번호}
bool chk[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }

  int cnt = 0;
  long long ans = 0;
  priority_queue< tuple<int,int,int>,
                  vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq;

  chk[1] = 1;
  for(auto nxt : adj[1])
    pq.push({nxt.X, 1, nxt.Y});  

  while(cnt < n - 1){
    int c, a, b;
    tie(c,a,b) = pq.top(); pq.pop();
    mx = max(c, mx);
    if(chk[b]) continue;
    ans += c;
    chk[b] = 1;
    cnt++;
    for(auto nxt : adj[b])
      if(!chk[nxt.Y]){
        pq.push({nxt.X, b, nxt.Y});
      }
  }
  cout << ans - mx;
}

// 두 개의 마을로 분할했는데 가중치의 합이 최소가 되게 하려면
// -> 처음 그래프에서 가중치가 가장 큰 간선을 끊어주면 된다!
