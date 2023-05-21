#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p[100005];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (p[u] < p[v]) p[u] = v;
    else p[v] = u;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    fill(p, p + n + 1, -1);

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ c, { a, b } });
    }
    sort(edges.begin(), edges.end());

    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (find(a) == find(b)) continue;
        is_diff_group(a, b);
        ans += cost;
        cnt++;
        if (cnt == n - 2) break;
    }
    cout << ans;

    return 0;
}
