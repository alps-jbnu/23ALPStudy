#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n,m,st,en;
vector<pair<int,int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단 거리 테이블


int func(int st, int en){
    fill(d, d+n+1, INF);
    priority_queue<pair<int,int>, 
                    vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[st] = 0;
    // 우선순위 큐에 (0, 시작점) 추가
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    return d[en];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> n >> m >> x;
    fill(d,d+n+1,INF);

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    int ans = 0;
    for(int st = 1; st <= n; st++)
        ans = max(ans, func(st, x) + func(x, st));
    cout << ans;
}
