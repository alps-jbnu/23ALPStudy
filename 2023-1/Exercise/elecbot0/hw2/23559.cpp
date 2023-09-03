#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<pair<int, int>> v;

bool compare_food(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first - p1.second > p2.first - p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> X;
    int ans = 0;
    int price = 0;
    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        v.emplace_back(A, B);
        ans += B;
        price += 1000;
    }
    sort(v.begin(), v.end(), compare_food);
    for (auto p : v) {
        if (price + 4000 > X || p.first - p.second < 0) break;
        ans += (p.first - p.second);
        price += 4000;
    }
    cout << ans;
    return 0;
}
