#include <iostream>
#include <algorithm>
using namespace std;

int n, passengers[50001], k;
int ps[50001];
int dp[3][50001];

int sum_of(int st, int en) {
    return ps[en] - ps[st-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i{1}; i<=n; i++) cin>>passengers[i];
    cin>>k;

    for(int i{1}; i<=n; i++) ps[i] = ps[i-1] + passengers[i];
    for(int i{1}; i<=n; i++) {
        if(i<k) continue;
        dp[0][i] = max(dp[0][i-1], sum_of(i-k+1, i));
    }
    for(int i{1}; i<=n; i++) {
        if(i<2*k) continue;
        dp[1][i] = max(dp[1][i-1], dp[0][i-k] + sum_of(i-k+1, i));
    }
    for(int i{1}; i<=n; i++) {
        if(i<3*k) continue;
        dp[2][i] = max(dp[2][i-1], dp[1][i-k] + sum_of(i-k+1, i));
    }

    cout<<dp[2][n];
    
    return 0;
}