#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;
    vector<pair<int,int>> carrots;
    for(int i = 0; i < N; i++)
    {
        int w, p; cin >> w >> p;
        carrots.push_back(make_pair(p,w));
    }
    sort(carrots.begin(), carrots.end());
    long long answer = 0;
    for(int i = 0; i < N; i++)
    {
        answer += (long long)(T - N + i) * carrots[i].first + carrots[i].second;
    }
    cout << answer;
    return 0;
}
