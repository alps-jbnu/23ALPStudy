// N일동안 매일 학식의 두 메뉴 중 정확히 하나를 골라서 먹어야 한다 무조건 하나는 먹어야한다

#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[100005];
int b[100005];
pair<int, int> c[100005];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int ans = 0;
    cin >> n >> x;
    int q, w;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        cin >> w;

        a[i] = q;
        b[i] = w;
        c[i].first = q - w;
        c[i].second = i;
    }
    sort(c, c + n, greater<>());

    for (int i = 0; i < n; i++)
    {
        int d = n - i - 1;   // 남은 날짜
        if (c[i].first <= 0) // 차이가 0 이하면 무조건 싼게 이득
        {
            ans += b[c[i].second];
            x -= 1000;
        }
        else if (x - 5000 >= d * 1000) // 5000원을 선택할때는 남은 날짜를 고려
        {
            ans += a[c[i].second];
            x -= 5000;
        }
        else
        {
            ans += b[c[i].second];
            x -= 1000;
        }
    }
    cout << ans;
    return 0;
}