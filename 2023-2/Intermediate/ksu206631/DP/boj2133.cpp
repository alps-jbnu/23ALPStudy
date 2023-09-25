#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int dp[32] = {0};
    
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i = 4; i<=n; i++){
        dp[i] = dp[i-2] *3;
        for(int j = 4; j<=i; j+=2){
            dp[i] += dp[i-j]*2;
        }
    }
    cout << dp[n];
    return 0;
    
    
}
