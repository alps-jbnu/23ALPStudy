#include <bits/stdc++.h>
using namespace std;

int psum[250001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        psum[i] = psum[i - 1] + a;
    }
    int mx_ans = 0;
    for (int i = x; i <= n; i++)
    {
        if (mx_ans < psum[i] - psum[i - x])
        {
            mx_ans = psum[i] - psum[i - x];
        }
    }
    if (mx_ans == 0)
    {
        cout << "SAD";
        return 0;
    }
    int cnt = 0;
    cout << mx_ans << '\n';
    for (int i = x; i <= n; i++)
    {
        if (mx_ans == psum[i] - psum[i - x])
        {
            cnt++;
        }
    }
    cout << cnt;
}