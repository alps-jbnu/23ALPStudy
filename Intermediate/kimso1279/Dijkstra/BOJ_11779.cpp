#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n,m,st,en;

// {비용, 정점 번호}
vector<pair<int,int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단 거리 테이블
int pre[2005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(d,d+n+1,INF);

    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    cin >> st >> en;

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
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << "\n";

    vector<int> path;
    int cur = en;
    while(cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(auto x : path) cout << x << " ";
}
