#include <bits/stdc++.h>
using namespace std;
int n, a;
long long dp[500005];
bool is_prime[500005];
vector<pair<int, int>> arr;
int zcnt = 1;

void make_prime()
{
    fill(is_prime, is_prime + 500005, true);
    is_prime[0] = false;
    is_prime[1] = false;
    int num = 10000 * n;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (is_prime[i] == false)
            continue;
        for (int j = i * i; j <= num; j += i)
        {
            is_prime[j] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int flag = -1;
        cin >> a;
        if (a == 0)
        {
            zcnt++;
            continue;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (a == arr[i].first)
            {
                flag = i;
                break;
            }
        }
        if (flag == -1)
        {
            arr.push_back({a, 1});
        }
        else
        {
            arr[flag].second++;
        }
    }
    make_prime();
    dp[0] = 1;
    for (auto cur : arr)
    {
        for (int i = n * 10000; i >= 0; i--)
        {
            for (int j = 1; j <= cur.second; j++)
            {
                if (i - cur.first * j < 0)
                    break;
                dp[i] += dp[i - cur.first * j];
            }
        }
    }
    long long ans = 0;
    for (int i = 2; i <= n * 10000; i++)
    {
        if (is_prime[i])
            ans += dp[i];
    }
    cout << ans * zcnt;
}

/*  Knapsack DP + 에라토스테네스의 체를 쓴다는 것은 발상함 그러나 knapsack dp를 구현하지 못함.
    그래서 이글을 참고하여 품 https://allmymight.tistory.com/106 */