#include <bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
using namespace std;

vector<pair<ll, pair<int, int>>> cow;         // 소 정보 저장
priority_queue<ii, vector<ii>, greater<>> pq; // 대기하는 소 저장

int a[100005]; // 도착시간
int t[100005]; // 식사시간

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> t[i];
        cow.push_back({a[i], {t[i], i}});
    }

    sort(cow.begin(), cow.end());

    int idx = 0;
    ll ans = 0;

    ll curtime;

    while (idx < n || pq.size() != 0)
    {
        while (idx < n && cow[idx].first <= curtime) // 대기하는 소 우선순위 큐에 삽입
        {
            pq.push({cow[idx].second.second, idx});
            idx++;
        }
        if (pq.size() != 0) // 대기하는 소가 있으면 최대값 계산해주기 & 현재시간에 식사시간 추가해주기
        {
            int cow_idx = pq.top().second;
            pq.pop();

            ans = max(ans, curtime - cow[cow_idx].first);
            curtime += cow[cow_idx].second.first;
        }
        else // 대기하는 소가 없으면 시간갱신
        {
            curtime = cow[idx].first + cow[idx].second.first;
            idx++;
        }
    }
    cout << ans;
}