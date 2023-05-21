// baekjoon - 1238번 파티

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int n,m,x;
int ans;
vector<pair<int,int>> adj[1001];
const int INF = 0x3f3f3f3f;

int func(int st, int en) {
    int d[1001];
    fill(d,d+n+1,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[st] = 0;
    pq.push({d[st], st});
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    return d[en];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    while(m--) {
        int u,v,t;
        cin >> u >> v >> t;
        adj[u].push_back({t,v});
    }
    for(int i=1; i<=n; i++) {
        ans = max(ans, func(i,x) + func(x,i));
    }
    cout << ans;
    
}