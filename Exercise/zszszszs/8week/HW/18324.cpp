#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll w = v[i].second;
        ll p = v[i].first;
        ans += w + p * (i + t - n) l
    }
}