#include <bits/stdc++.h>

using namespace std;

int parent[51];
char lan[51][51];

int _find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = _find(parent[x]);
}

bool _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if(x == y) return false;
    else if(x > y)
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        parent[i] = i;
    priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>> pq;
    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> lan[i][j];
            if(lan[i][j] != '0')
            {
                if(lan[i][j] >= 'a' && lan[i][j] <= 'z')
                {
                    if(i != j)
                        pq.push(make_pair(lan[i][j] - 'a' + 1, make_pair(i, j)));
                    answer += lan[i][j] - 'a' + 1;
                }
                else
                {
                    if(i != j)
                        pq.push(make_pair(lan[i][j] - 'A' + 27, make_pair(i, j)));
                    answer += (lan[i][j] - 'A') + 27;
                }
            }
        }
    }
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(_union(cur.second.first, cur.second.second))
            answer -= cur.first;
    }
    for(int i = 2; i <= N; i++)
    {
        if(_find(i) != 1)
        {
            answer = -1;
            break;
        }
    }
    cout << answer;
    return 0;
}
