//baekjoon 1504번 특정한 최단 경로 

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int n,e,mida,midb;
vector<pair<int,int>> adj[801];
const int INF = 0x3f3f3f3f;

long long func(int st, int en) {
    int d[801];
    fill(d,d+n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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
    cin >> n >> e;
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});        
        adj[b].push_back({c,a});
    }
    cin >> mida >> midb;
    long long tempa = func(1,mida) + func(mida,midb) + func(midb, n);
    long long tempb = func(1,midb) + func(midb,mida) + func(mida, n);
    long long ans = min(tempa,tempb);
    if(ans >= INF) cout << -1;
    else cout << ans;
}