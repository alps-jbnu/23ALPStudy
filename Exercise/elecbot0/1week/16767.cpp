#include <bits/stdc++.h>

#define ii pair<int, int>
#define ll long long

using namespace std;

int N;
priority_queue<ii, vector<ii>, greater<>> cow_data;
priority_queue<int, vector<int>, greater<>> pq;
int a[100001];
int t[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> t[i];
        cow_data.emplace(a[i], i);
    }
    ll time = 0;
    ll eat_start_time = 0;
    ll eat_time = 0;
    ll max_time = 0;
    while (!cow_data.empty() || !pq.empty()) {
        time += 1;
        while (!cow_data.empty()) {
            auto cur = cow_data.top();
            if (cur.first > time) break;
            pq.emplace(cur.second);
            cow_data.pop();
        }
        if (!pq.empty() && eat_start_time + eat_time <= time) { // < or <=
            int cur = pq.top(); pq.pop();
            eat_start_time = time;
            eat_time = t[cur];
            max_time = max(max_time, time - a[cur]);
        }
    }
    cout << max_time;
    return 0;
}
