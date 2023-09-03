#include <bits/stdc++.h>

using namespace std;

int M, N, L;
set<int> x;
set<int, greater<>> x2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >> L;
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        x.emplace(num);
        x2.emplace(num);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        if (b > L) continue;
        auto lower = x.lower_bound(a);
        auto lower2 = x2.lower_bound(a);
        if (lower != x.end()) {
            if (abs(*lower - a) + b <= L) {
                ans += 1;
                continue;
            }
        }
        if (lower2 != x2.end()) {
            if (abs(*lower2 - a) + b <= L) {
                ans += 1;
                continue;
            }
        }
    }
    cout << ans;
    return 0;
}
