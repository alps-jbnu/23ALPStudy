#include <bits/stdc++.h>

using namespace std;

int connectNum[100001];
vector<pair<int,int>> connect;
vector<int> beRemoved;
bool notInitConnect[100001];

int _find(int x) {
    if(connectNum[x] < 0) return x;
    return connectNum[x] = _find(connectNum[x]);
}

long long _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if(x == y) return 0;

    long long ret = connectNum[x] * connectNum[y];

    if(connectNum[x] <= connectNum[y])
    {
        connectNum[x] += connectNum[y];
        connectNum[y] = x;
    }
    else
    {
        connectNum[y] += connectNum[x];
        connectNum[x] = y;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q; cin >> N >> M >> Q;
    fill(connectNum, connectNum + N + 1, -1);
    connect.push_back(make_pair(0,0));
    for(int i = 0; i < M; i++)
    {
        int X, Y; cin >> X >> Y;
        connect.push_back(make_pair(X, Y));
    }
    for(int i = 1; i <= Q; i++)
    {
        int A; cin >> A;
        beRemoved.push_back(A);
        notInitConnect[A] = true;
    }
    for(int i = 1; i <= M; i++)
    {
        if(!notInitConnect[i])
        {
            _union(connect[i].first, connect[i].second);
        }
    }
    long long answer = 0;
    for(int i = beRemoved.size() - 1; i >= 0; i--)
    {
        answer += _union(connect[beRemoved[i]].first, connect[beRemoved[i]].second);
    }
    cout << answer;
    return 0;
}
