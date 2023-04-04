#include<bits/stdc++.h>
using namespace std;

int sum[50005];         //각 객차까지의 승객 수의 합
int dp[10][50005];      //[소형기관차번호][객차번호]
int result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    int k;
    cin >> k;

    //객차는 1번부터 3번까지
    for (int i = 1; i <= 3; i++) {
        //j번째까지의 객차를 선택하기 때문에 i*k번째 객차부터 선택
        for (int j = i * k; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + sum[j] - sum[j - k]);
        }
    }

    cout << dp[3][n];

    return 0;
}