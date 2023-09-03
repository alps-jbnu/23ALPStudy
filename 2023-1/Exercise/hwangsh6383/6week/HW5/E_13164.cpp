#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("../example.txt", "r", stdin);

    int N, K; cin >> N >> K;
    vector<int> v;
    for(int i = 0; i < N; i++)
    {
        int height; cin >> height;
        v.push_back(height);
    }
    for(int i = N - 1; i > 0; i--)
        v[i] -= v[i - 1];
    v[0] = 0x7fffffff;
    sort(v.begin(), v.end());
    int answer = 0;
    for(int i = 0; i < N - K; i++)
    {
        answer += v[i];
    }
    cout << answer;

    return 0;
}
