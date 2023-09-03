#include <bits/stdc++.h>

using namespace std;

int custsum[50001];
int dp[4][50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int car; cin >> car;
    int cust;
    for(int i = 1; i <= car; i++)
    {
         cin >> cust;
        custsum[i] = custsum[i - 1] + cust;
    }
    int maxCar; cin >> maxCar;

    for(int i = 1; i <= 3; i++)
    {
        for(int j = i * maxCar; j <= car; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - maxCar] + custsum[j] - custsum[j - maxCar]);
        }
    }
    cout << dp[3][car];
    return 0;
}
