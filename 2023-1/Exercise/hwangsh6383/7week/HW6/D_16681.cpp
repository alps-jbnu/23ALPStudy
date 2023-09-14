#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 2e14

int h[100001];
vector<pair<int,long long>> up[100001];
vector<pair<int,long long>> down[100001];
long long dup[100001];
long long ddown[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, D, E; cin >> N >> M >> D >> E;
    for (int i = 2; i < N; ++i) {
        dup[i] = ddown[i] = MAX_VALUE;
    }
    dup[N] = MAX_VALUE;
    ddown[1] = MAX_VALUE;
    for (int i = 1; i <= N; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < M; ++i) {
        int a, b, n; cin >> a >> b >> n;
        if(h[a] < h[b])
        {
            up[a].push_back(make_pair(b, n));
            down[a].push_back(make_pair(b, n));
        }
        else if(h[a] > h[b])
        {
            up[b].push_back(make_pair(a, n));
            down[b].push_back(make_pair(a, n));
        }
    }

    priority_queue<pair<long long,int>,
                vector<pair<long long,int>>,
                    greater<pair<long long,int>>> pq;

    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > dup[cur.second])
            continue;
        for(auto nxt : up[cur.second])
        {
            if(dup[nxt.first] > dup[cur.second] + nxt.second)
            {
                dup[nxt.first] = dup[cur.second] + nxt.second;
                pq.push(make_pair(dup[nxt.first], nxt.first));
            }
        }
    }
    pq.push(make_pair(0, N));
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > ddown[cur.second])
            continue;
        for(auto nxt : down[cur.second])
        {
            if(ddown[nxt.first] > ddown[cur.second] + nxt.second)
            {
                ddown[nxt.first] = ddown[cur.second] + nxt.second;
                pq.push(make_pair(ddown[nxt.first], nxt.first));
            }
        }
    }

    long long answer = -MAX_VALUE;
    for(int i = 2; i < N; i++)
    {
        if(dup[i] != MAX_VALUE || ddown[i] != MAX_VALUE)
        {
            answer = max(answer, h[i] * E - D * (dup[i] + ddown[i]));
        }
    }
    if(answer == -MAX_VALUE)
        cout << "Impossible";
    else
        cout << answer;
    return 0;
}
