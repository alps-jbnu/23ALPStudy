#include <bits/stdc++.h>
using namespace std;

int p[100005];
int nd[100005];
int ground[100005];
int n, m, h, a, b, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ground[i]; // 초기값
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> k;
        p[a] += k;
        p[b + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
    {
        p[i] += p[i - 1];
        cout << ground[i] + p[i] << ' ';
    }
}
