#include <bits/stdc++.h>

using namespace std;

int N, M, C;
vector<int> t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) {
        int t_i; cin >> t_i;
        t.emplace_back(t_i);
    }
    sort(t.begin(), t.end());
    int start = 0;
    int end = 1000000000;
    while (start + 1 < end) {
        int mid = (start + end) / 2;
        int cur_M = M - 1; // BUS COUNT
        int cur_C = C - 1;
        int start_time = t[0];
        bool check = true;
        for (int i = 1; i < t.size(); i++) {
            int time = t[i];
            if (time - start_time > mid || cur_C == 0) {
                if (cur_M == 0) {
                    check = false;
                    break;
                }
                cur_M -= 1;
                cur_C = C - 1;
                start_time = time;
            } else {
                cur_C -= 1;
            }
        }
        if (check) {
            end = mid;
        } else {
            start = mid;
        }
    }
    cout << end;
    return 0;
}
