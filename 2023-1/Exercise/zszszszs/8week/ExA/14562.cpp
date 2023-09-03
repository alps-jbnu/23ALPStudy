#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int s, t;
        cin >> s >> t;
        queue<pair<pair<int, int>, int>> q;
        q.push({{s, t}, 0});
        while (!q.empty())
        {

            auto cur = q.front();
            int x = cur.first.first;
            int y = cur.first.second;
            int cnt = cur.second;
            q.pop();
            if (x == y)
            {
                cout << cur.second << '\n';
                break;
            }
            q.push({{x + 1, y}, cnt + 1});
            if (x > y)
                continue;
            q.push({{x * 2, y + 3}, cnt + 1});
        }
    }
}