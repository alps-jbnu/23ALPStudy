#include<bits/stdc++.h>
using namespace std;
#define ll long long

int arr[100005];
int eat[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> info;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> eat[i];
        info.push({ arr[i],i });
    }

    ll time = 0;
    ll eatTime = 0;
    ll startTime = 0;
    ll result = 0;

    while (!info.empty() || !pq.empty()) {
        time++;

        while (!info.empty()) {
            auto cur = info.top();

            if (cur.first > time)
                break;

            pq.push(cur.second);
            info.pop();
        }

        if (!pq.empty() && eatTime + startTime <= time) {
            int cur = pq.top();
            pq.pop();
            startTime = time;
            eatTime = eat[cur];
            result = max(result, time - arr[cur]);
        }
    }

    cout << result;

    return 0;
}