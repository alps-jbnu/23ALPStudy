#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    vector<pair<int,int>> beers;
    for(int i = 0; i < K; i++)
    {
        int v, c; cin >> v >> c;
        beers.push_back(make_pair(c, v));
    }
    sort(beers.begin(), beers.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int preference = 0;
    for(auto beer : beers)
    {
        if(pq.size() == N)
        {
            preference -= pq.top();
            pq.pop();
        }
        pq.push(beer.second);
        preference += beer.second;
        if(pq.size() == N && preference >= M)
        {
            cout << beer.first;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
