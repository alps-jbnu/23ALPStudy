#include <iostream>
#include <algorithm>
using namespace std;

int fib[42][2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, dp[501][501]={0,}, a[501][501];
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++) cin >> a[i][j];
    }
    //초기값
    dp[1][1] = a[1][1];

    //점화식
    for(int i=2; i <= n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
        }
    }

    int max = 0;
    for(int i=1; i<=n; i++){
        if(max < dp[n][i]) max = dp[n][i];
    }

    cout << max << "\n";
}
