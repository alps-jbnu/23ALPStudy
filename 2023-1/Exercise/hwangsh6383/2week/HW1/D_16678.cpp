#include <bits/stdc++.h>

using namespace std;

vector<int> pride;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long answer = 0;
    for(int i = 1; i <= N; i++)
    {
        int p; cin >> p;
        pride.push_back(p);
    }
    sort(pride.begin(), pride.end());
    int index = 1;
    for(int i = 0; i < N; i++)
    {
        if(pride[i] >= index)
        {
            answer += pride[i] - index;
            index++;
        }
    }
    cout << answer;
    return 0;
}
