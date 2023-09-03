#define INF 2147483647
#include <iostream>
using namespace std;

int n, m;
bool available[101];
int dp[101][101];

int total_price(int cur, int coupons) {
    if(cur>n) return 0;
    int& dp_cur = dp[cur][coupons];
    if(dp_cur != INF) return dp_cur;
    if(!available[cur]) return dp_cur = total_price(cur+1, coupons);
    dp_cur = total_price(cur+1, coupons) + 10000;
    dp_cur = min(dp_cur, total_price(cur+3, coupons+1) + 25000);
    dp_cur = min(dp_cur, total_price(cur+5, coupons+2) + 37000);
    if(coupons>=3) dp_cur = min(dp_cur, total_price(cur+1, coupons-3));
    return dp_cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i{0}; i<101; i++) available[i] = true;
    for(int i{1}; i<101; i++) {
        for(int j{}; j<101; j++) dp[i][j] = INF;
    }

    cin>>n>>m;
    for(int i{}; i<m; i++) {
        int unav;
        cin>>unav;
        available[unav] = false;
    }
    cout<<total_price(1, 0);

    return 0;
}