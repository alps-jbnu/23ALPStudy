#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

// d[i][k] : i번째 자리수 중 k로 끝나는 수의 개수
long long d[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    // d[1][k]에서, k!=0인 모든 값은 1, 총 합 9
    for (int i = 1; i <= 9; i++) d[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= 9; k++) {
            // k!=0 && k!=9 일 때 
            // d[i][k] = d[i-1][k-1] + d[i-1][k+1]
            if (k != 0) d[i][k] += d[i - 1][k - 1];
            if (k != 9) d[i][k] += d[i - 1][k + 1];
            d[i][k] %= 1000000000;
        }
    }

    long long int ans = 0;
    for (int i = 0; i <= 9; i++) ans += d[n][i];

    ans %= 1000000000;

    cout << ans << '\n';

    return 0;
}
