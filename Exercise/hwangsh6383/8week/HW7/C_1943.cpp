#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 3; i++)
    {
        int N; cin >> N;
        vector<pair<int,int>> v;
        int sum = 0;
        for(int j = 0; j < N; j++)
        {
            int coin, num; cin >> coin >> num;
            v.push_back(make_pair(coin, num));
            sum += coin * num;
        }
        if(sum % 2)
        {
            cout << 0 << '\n';
            continue;
        }
        bool dp[50001] = { false, };
        dp[0] = true;
        for(int j = 0; j < N; j++)
        {
            for(int k = sum / 2; k >= v[j].first; k--)
            {
                if(dp[k - v[j].first])
                {
                    for(int m = 0; m < v[j].second && (k + m * v[j].first) <= sum / 2; m++)
                        dp[k + m * v[j].first] = true;
                }
            }
        }
        cout << dp[sum/2] << '\n';
    }
    return 0;
}
