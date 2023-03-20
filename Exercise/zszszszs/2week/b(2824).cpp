#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1000000000;

ll gcd(ll low, ll high)
{
    return high % low ? gcd(high % low, low) : low;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ll a[1005];
    ll m;
    ll b[1005];
    ll ans = 1;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll gc;
            if (a[i] >= b[j])
            {
                gc = gcd(b[j], a[i]);
            }
            else
            {
                gc = gcd(a[i], b[j]);
            }
            a[i] /= gc;
            b[j] /= gc;
            ans *= gc;
            if (ans >= INF)
            {
                ans %= INF;
                flag = true;
            }
        }
    }
    if (flag)
    {
        int tmp = ans;
        int num = 0;
        if (tmp == 0)
            num++;
        while (tmp != 0)
        {
            tmp /= 10;
            num++;
        }

        for (int i = 0; i < 9 - num; i++)
        {
            cout << 0;
        }
    }
    cout << ans;
}