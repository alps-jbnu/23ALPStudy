#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.first > b.first) return true;
    else if(a.first == b.first) {
        if(a.second < b.second) return true;
    }
    else {
        return false;
    }
    return false;
}

const long long INF =  0x7f7f7f7f7f7f;
vector<pair<long long,int>> adj[100001];
long long d[100001];
int n,m,k;
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> >pq;


void func() {
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

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    fill(d,d+n+1, INF);
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({w,u});
    }
    int ct;
    while(k--) {
        cin >> ct;
        d[ct] = 0;
        pq.push({d[ct],ct});
    }
    func();
    int ans = max_element(d+1, d+n+1) - d;
    cout << ans << '\n' << d[ans];

}