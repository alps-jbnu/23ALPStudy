#include <bits/stdc++.h>

using namespace std;

int N, R;
vector<pair<int, int>> line[200001];
bool vst[200001];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> R;
    for (int i = 0; i < N - 1; i++) {
        int a, b, d; cin >> a >> b >> d;
        line[a].emplace_back(b, d);
        line[b].emplace_back(a, d);
    }
    bool giga_start = false;
    q.emplace(R, 0);
    vst[R] = true;
    int max_branch_size = 0;
    int trunk_size = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cnt_q_add = 0;
        for (auto nxt : line[cur.first]) {
            if (vst[nxt.first]) continue;
            vst[nxt.first] = true;
            cnt_q_add += 1;
            q.emplace(nxt.first, cur.second + nxt.second);
        }
        if (!giga_start && cnt_q_add != 1) {
            giga_start = true;
            trunk_size = cur.second;
        } else if (cnt_q_add == 0) {
            max_branch_size = max(max_branch_size, cur.second - trunk_size);
        }
    }
    cout << trunk_size << " " << max_branch_size;
    return 0;
}
