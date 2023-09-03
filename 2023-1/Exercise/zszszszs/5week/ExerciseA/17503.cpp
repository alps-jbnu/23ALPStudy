#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<pair<int, int>> v;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b; // 선호도, 도수
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool
         { return p1.second < p2.second; });

    priority_queue<int, vector<int>, cmp> pq;
    
    ll total = 0;
    for (auto beer : v)
    {
        total += beer.first;
        pq.push(beer.first);

        if (pq.size() > n)
        {
            total -= pq.top();
            pq.pop();
        }

        if (pq.size() == n && total >= m)
        {
            cout << beer.second << endl;
            return 0;
        }
    }
    cout << -1;
}
