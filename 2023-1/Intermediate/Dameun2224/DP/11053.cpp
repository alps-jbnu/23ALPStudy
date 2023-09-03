#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int a[1005];
int d[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = 1;
    }
    
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            // a[i]보다 작으면서 합이 최댓값인 수 찾기
            if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
        }
        ans = max(ans, d[i]);
    }

    cout << ans << '\n';

    return 0;
}
