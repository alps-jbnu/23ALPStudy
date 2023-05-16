#include <bits/stdc++.h>
using namespace std;

pair<string, int> p[105];
bool chk[105];
int m, e, b;

int chkposition()
{
    if (m == e == b)
    {
        return 1;
    }
    if (m == e && m > b)
    {
        return 2;
    }
    if (m == b && m > e)
    {
        return 3;
    }
    if (b == e && b > m)
    {
        return 4;
    }
    if (m > b && m > e)
    {
        return 5;
    }
    if (b > e && b > m)
    {
        return 6;
    }
    if (e > b && e > m)
    {
        return 7;
    }
    return 0;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    m = 7;
    e = 7;
    b = 7;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int day;
        string name;
        int num;
        cin >> day >> name >> num;
        p[day] = {name, num};
        chk[day] = true;
    }
    int prev_pos = 1;
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (chk[i] == false)
            continue;
        if (p[i].first == "Mildred")
        {
            m += p[i].second;
        }
        if (p[i].first == "Elsie")
        {
            e += p[i].second;
        }
        if (p[i].first == "Bessie")
        {
            b += p[i].second;
        }
        int current_pos = chkposition();
        if (prev_pos != current_pos)
        {
            ans++;
            prev_pos = current_pos;
        }
    }
    cout << ans;
}