#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        result += v[i].second;
        x -= 1000;
    }

    sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b) {
        return abs(a.first - a.second) > abs(b.first - b.second);
        });

    for (int i = 0; i < n; i++) {
        if (x >= 4000 && v[i].first - v[i].second >= 0) {
            x -= 4000;
            result += v[i].first - v[i].second;
        }
    }

    cout << result;
}