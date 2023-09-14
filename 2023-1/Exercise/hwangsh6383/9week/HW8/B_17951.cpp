#include <bits/stdc++.h>

using namespace std;

int dp[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        int x; cin >> x;
        dp[i] = dp[i - 1] + x;
    }
    int answer = 0;
    int s = 0, e = dp[N];
    while(s <= e)
    {
        int mid = (s + e) / 2;

        int i = 0, j = 1;
        int group = 0;
        while(j <= N)
        {
            if(mid <= dp[j] - dp[i])
            {
                group++;
                i = j;
            }
            j++;
        }

        if(group >= K)
        {
            answer = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << answer;
    return 0;
}
