#define MAX 1001
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int t{}; t<3; t++) {
        int N{};
        int total{}, half{};
        pair<int, int> coins[101]; // {value, # of coin}
        bool dp[50001];

        for(int i{}; i<101; i++) coins[i] = {0, 0};
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        cin>>N;
        for(int i{}; i<N; i++) {
            cin>>coins[i].first>>coins[i].second;
            total += coins[i].first*coins[i].second;
        }
        half = total/2;
        if(half*2==total) {
            for(int i{}; i<N; i++) {
                int coin_value{coins[i].first};
                int coin_num{coins[i].second};
                for(int j{50000}; j>=0; j--) {
                    if(j-coin_value<0) continue;
                    if(dp[j-coin_value]) {
                        for(int k{}; k<coin_num; k++) {
                            int nxt{j+coin_value*k};
                            if(nxt>50000) break;
                            dp[nxt] = true;
                        }
                    }
                }
            }
        }
        cout<<dp[half]<<"\n";
    }

    return 0;
}