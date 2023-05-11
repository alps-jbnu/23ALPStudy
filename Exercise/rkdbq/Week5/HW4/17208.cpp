#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, ans;
vector<pair<int, int>> orders;
int dp[101][301][301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>K;
    for(int i{}; i<N; i++) {
        int x, y;
        cin>>x>>y;
        orders.push_back({x, y});
    }

    for(int i{1}; i<=M; i++) {
        for(int j{1}; j<=K; j++) {
            auto cur{orders[0]};  
            if(cur.first<=i && cur.second<=j) {
                dp[0][i][j] = 1;
            }
            else {
                dp[0][i][j] = 0;
            }
        }
    }

    for(int i{1}; i<N; i++) {
        for(int j{1}; j<=M; j++) {
            for(int k{1}; k<=K; k++) {
                auto cur{orders[i]};
                if(cur.first<=j && cur.second<=k) {
                    dp[i][j][k] = max(dp[i-1][j-cur.first][k-cur.second]+1, dp[i-1][j][k]);
                }
                else {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }

    cout<<dp[N-1][M][K];

    return 0;
}