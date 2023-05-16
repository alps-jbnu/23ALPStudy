#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long int
using namespace std;

bool comp(pii x, pii y)
{
    return x.second < y.second;
}

struct compare
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};

ll N, M, K, result = 0;
vector<pii> vec;
priority_queue<int, vector<int>, compare> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++)
    {
        int k, c; cin >> k >> c;
        vec.push_back({ k, c });
    }
    sort(vec.begin(), vec.end(), comp);

    for(auto it : vec)
    {
        pq.push(it.first);
        result += it.first;

        if(pq.size() > N)
        {
            result -= pq.top();
            pq.pop();
        }

        if(pq.size() == N && result >= M)
        {
            cout << it.second;
            return 0;
        }
    }
    cout << -1;

    return 0;
}