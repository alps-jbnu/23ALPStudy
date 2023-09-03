#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> p(1005, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

double distance(pair<int, int> x, pair<int, int> y) {
    return sqrt(pow((x.first - y.first), 2) + pow((x.second - y.second), 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> god(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> god[i].first >> god[i].second;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        is_diff_group(x, y);
    }

    vector<pair<double, pair<int, int>>> edge;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double dist = distance(god[i], god[j]);
            edge.push_back({dist, {i, j}});
        }
    }

    sort(edge.begin(), edge.end());

    double ans = 0;
    int cnt = 0;
    for (const auto& e : edge) {
        double dist = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (is_diff_group(u, v)) {
            ans += dist;
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}
