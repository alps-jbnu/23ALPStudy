#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[100005];
bool chk[100005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }

    int cnt = 0, ans = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    chk[1] = true;
    for (auto nxt : adj[1]) pq.push({ nxt.X, 1, nxt.Y });   // cost,a,b

    int mx = 0;
    while (cnt < n - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        chk[b] = true;
        cnt++;
        ans += cost;
        mx = max(mx, cost);
        for (auto nxt : adj[b])
            pq.push({ nxt.X, b,nxt.Y });
    }

    ans -= mx;
    cout << ans << '\n';

    return 0;
}
