#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, bool> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d; cin >> a >> b >> c >> d;
    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    m[make_pair(0, 0)] = true;
    int answer = 0;
    while(!q.empty())
    {
        int qs = q.size();
        while(qs--)
        {
            auto cur = q.front(); q.pop();
            if(cur.first == c && cur.second == d)
            {
                cout << answer;
                return 0;
            }
            if(m.find(make_pair(a, cur.second)) == m.end())
            {
                m[make_pair(a, cur.second)] = true;
                q.push(make_pair(a, cur.second));
            }
            if(m.find(make_pair(cur.first, b)) == m.end())
            {
                m[make_pair(cur.first, b)] = true;
                q.push(make_pair(cur.first, b));
            }
            if(m.find(make_pair(0, cur.second)) == m.end())
            {
                m[make_pair(0, cur.second)] = true;
                q.push(make_pair(0, cur.second));
            }
            if(m.find(make_pair(cur.first, 0)) == m.end())
            {
                m[make_pair(cur.first, 0)] = true;
                q.push(make_pair(cur.first, 0));
            }
            int A_rest = a - cur.first;
            if(A_rest > 0)
            {
                if(A_rest >= cur.second)
                {
                    if(m.find(make_pair(cur.first + cur.second, 0)) == m.end())
                    {
                        m[make_pair(cur.first + cur.second, 0)] = true;
                        q.push(make_pair(cur.first + cur.second, 0));
                    }
                }
                else
                {
                    if(m.find(make_pair(a, cur.second - A_rest)) == m.end())
                    {
                        m[make_pair(a, cur.second - A_rest)] = true;
                        q.push(make_pair(a, cur.second - A_rest));
                    }
                }
            }
            int B_rest = b - cur.second;
            if(B_rest > 0)
            {
                if(B_rest >= cur.first)
                {
                    if(m.find(make_pair(0, cur.first + cur.second)) == m.end())
                    {
                        m[make_pair(0, cur.first + cur.second)] = true;
                        q.push(make_pair(0, cur.first + cur.second));
                    }
                }
                else
                {
                    if(m.find(make_pair(cur.first - B_rest, b)) == m.end())
                    {
                        m[make_pair(cur.first - B_rest, b)] = true;
                        q.push(make_pair(cur.first - B_rest, b));
                    }
                }
            }
        }
        answer++;
    }
    cout << -1;
    return 0;
}
