//문제번호: 1414 불우이웃돕기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;

int N;
vector<int> p(10005, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
}

tuple<int, int, int> edge[55];
int idx = 0;
int total_lan_len = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char alpa; cin >> alpa;

            if (alpa == '0') {
                continue;
            }
            else if (alpa - 0 >= 97) { //소문자
                edge[idx] = { alpa - 96, i, j};
                total_lan_len += (alpa - 96);
                //cout << alpa - 96 << '\n';
                idx++;
            }
            else if (alpa - 0 >= 65) { //대문자
                edge[idx] = { alpa - 65 + 27, i, j };
                total_lan_len += (alpa - 65 + 27);
                //cout << alpa - 64 << '\n';
                idx++;
            }
        }
    }

    //cout << total_lan_len << '\n';

    sort(edge, edge + idx);
    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < idx; i++) {
        int a, b, cost;

        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if (cnt == N - 1) break;
    }

    if (cnt < N - 1) {
        cout << "-1";
        return 0;
    }
    
    cout << total_lan_len - ans;
}

