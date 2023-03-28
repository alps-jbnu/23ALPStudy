#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N, K;
int ps[50'005];
int dp[4][50'005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        ps[i] = ps[i - 1] + num;
    }
    
    cin >> K;

    for (int i = 1; i <= 3; i++) {
        for (int j = i * K; j <= N; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - K] + ps[j] - ps[j - K]);
        }
    }

    cout << dp[3][N];
}

