#include <bits/stdc++.h>

using namespace std;

bool notPrime[500001];
int _count[10001] = {0, };
long long dp[500001] = {0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i <= 250000; i++)
    {
        if(notPrime[i]) continue;
        for(int j = i + i; j <= 500000; j += i)
        {
            notPrime[j] = true;
        }
    }

    int N; cin >> N;
    int count0 = 1;
    vector<int> candy;
    for(int i = 0; i < N; i++)
    {
        int n; cin >> n;
        if(n == 0)
        {
            count0++;
            continue;
        }
        if(_count[n] == 0)
            candy.push_back(n);
        _count[n]++;
    }
    dp[0] = 1;
    int maxi = 0;
    for(int i = 0; i < candy.size(); i++)
    {
        for(int j = maxi; j >= 0; j--)
        {
            for(int k = 1; k <= _count[candy[i]]; k++)
            {
                if(j + k * candy[i] > 500000) break;
                dp[j + k * candy[i]] += dp[j];
            }
        }
        maxi += candy[i] * _count[candy[i]];
        maxi = min(maxi, 500000);
    }
    long long answer = 0;
    for(int i = 2; i <= maxi; i++)
    {
        if(notPrime[i]) continue;
        answer += dp[i];
    }
    answer *= count0;
    cout << answer;
    return 0;
}
