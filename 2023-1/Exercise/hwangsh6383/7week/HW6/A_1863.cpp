#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int,int>> v;
    stack<int> s;
    for(int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    int answer = 0;
    for(auto cur : v)
    {
        int h = cur.second;
        if(s.empty())
        {
            if(h != 0)
                answer++;
            s.push(h);
        }
        else if(s.top() > h)
        {
            while(!s.empty() && s.top() > h)
            {
                s.pop();
            }
            if(s.empty() || s.top() < h)
            {
                if(h != 0)
                    answer++;
                s.push(h);
            }
        }
        else if(s.top() < h)
        {
            if(h != 0)
                answer++;
            s.push(h);
        }
    }
    cout << answer;
    return 0;
}
