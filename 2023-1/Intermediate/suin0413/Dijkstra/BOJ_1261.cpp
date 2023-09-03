#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;
int a[105][105];
int d[105][105];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);  
  cin >> m >> n;
  for(int i = 1;i<=n;i++){
    string s;
    cin >> s;
    for(int j = 1;j<=m;j++){
        a[i][j] = s[j-1] - '0';
    }
  }
  for(int i = 1;i<=n;i++) fill(d[i], d[i]+1+m, INF);
  
  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
  // {비용, {X,Y}}
  d[1][1] = 0;
  pq.push({d[1][1], {1,1}}); 
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y.X][cur.Y.Y] != cur.X) continue;
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 살펴보기
        pair<int,int> nxt;
        nxt.X = cur.Y.X + dx[dir];
        nxt.Y = cur.Y.Y + dy[dir];
        if(nxt.X < 1 || nxt.X > n || nxt.Y < 1 || nxt.Y > m) continue; // 범위 밖
        if(d[nxt.X][nxt.Y] <= d[cur.Y.X][cur.Y.Y]+a[nxt.X][nxt.Y]) continue;
        // cur을 거쳐가는 것이 더 작은 값을 가질 경우
        d[nxt.X][nxt.Y] = d[cur.Y.X][cur.Y.Y]+a[nxt.X][nxt.Y];
        pq.push({d[nxt.X][nxt.Y], {nxt.X, nxt.Y}});
    }
  }

  cout << d[n][m];
  
}
