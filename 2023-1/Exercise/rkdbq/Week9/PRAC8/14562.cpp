#define INF 2147483647
#define MAX 250001
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int kick(int s, int t) {
    if(s>t) return INF;
    if(dp[s][t] == INF) dp[s][t] = min(kick(s*2, t+3), kick(s+1, t)) + 1;
    return dp[s][t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin>>C;
    for(int c{}; c<C; c++) {
        for(int i{}; i<1001; i++) {
            for(int j{}; j<1001; j++) {
                dp[i][j] = INF;
                if(i==j) dp[i][j] = 0;
            }
        }
        int S, T;
        cin>>S>>T;
        cout<<kick(S, T)<<"\n";
    }

    return 0;
}