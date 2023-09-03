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
    m++;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        // 0이 오르막기
        c = !c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }

    int cnt = 0, mn = 0, mx = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq1;

    chk[0] = true;
    for (auto nxt : adj[0]) pq1.push({ nxt.X, 0, nxt.Y });   // cost,a,b
    while (cnt < n) {
        int cost, a, b;
        tie(cost, a, b) = pq1.top(); pq1.pop();
        if (chk[b]) continue;
        chk[b] = true;
        cnt++;
        mn += cost;
        for (auto nxt : adj[b]) 
            pq1.push({ nxt.X, b, nxt.Y });
        
            
    }

    fill(chk, chk + n + 1, false);

    cnt = 0;
    priority_queue<tuple<int, int, int>> pq2;

    chk[0] = true;
    for (auto nxt : adj[0]) pq2.push({ nxt.X, 0, nxt.Y });   // cost,a,b
    while (cnt < n) {
        int cost, a, b;
        tie(cost, a, b) = pq2.top(); pq2.pop();
        if (chk[b]) continue;
        chk[b] = true;
        cnt++;
        mx += cost;
        for (auto nxt : adj[b])
            pq2.push({ nxt.X, b,nxt.Y });
    }

    int ans = mx * mx - mn * mn;
    cout << ans << '\n';

    return 0;
}
