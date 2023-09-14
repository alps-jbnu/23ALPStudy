#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
vector<pair<int, int>> adj[1005];
bool chk[1005];
int ans, cnt;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        int a;
        cin >> a;
        chk[a] = true;
    }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
        adj[v].push_back({ w,u });
    }

    priority_queue< tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>> > pq;

    for (int i = 1; i <= n; i++) {
        if (!chk[i]) continue;
        for (auto nxt : adj[i]) pq.push({ nxt.X,1,nxt.Y });
    }
    

    while (cnt < n - k) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        chk[b] = 1;
        ans += cost;
        cnt++;
        for (auto nxt : adj[b]) pq.push({ nxt.X,b,nxt.Y });
    }
    
    cout << ans << '\n';

    return 0;
}
