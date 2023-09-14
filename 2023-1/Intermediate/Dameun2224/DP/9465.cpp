#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string.h>
using namespace std;

int a[3][100005];
int d[3][100005][2];
// d[i][j][1] : a[i][j]를 떼었을 때 최댓값
// d[i][j][0] : a[i][j]를 떼지 않았을 때 최댓값
// 1 2 3 4 5
// 6 7 8 9 10
// 일 때, 1 6 2 7 .. 순으로 왼쪽 위부터 아래로, 오른쪽으로 진행
// a[i][j]를 뗐을 때 최대값, 떼지 않았을 때 최대값 저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n = 0;
    cin >> t;

    while (t--) {
        // d 함수 초기화
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= 1; k++)
                    d[i][j][k] = 0;
        cin >> n;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        d[1][1][1] = a[1][1];   // a[1][1] 더한 최댓값
        d[1][1][0] = 0;         // a[1][1] 더하지 않은 최댓값
        d[2][1][1] = a[2][1];   // a[2][1] 더한 최댓값
        d[2][1][0] = a[1][1];   // a[2][1] 더하지 않은 최댓값
        int ans = max(a[1][1], a[2][1]);
        for (int i = 2; i <= n; i++) {
            d[1][i][1] = max(d[1][i - 1][0], d[2][i - 1][1]) + a[1][i];
            d[1][i][0] = max(d[2][i - 1][1], d[2][i - 1][0]);
            d[2][i][1] = max(d[1][i - 1][1], d[1][i - 1][0]) + a[2][i];
            d[2][i][0] = max(d[1][i][1], d[1][i][0]);
            ans = max(max(d[1][i][1], d[1][i][0]), max(d[2][i][1], d[2][i][0]));
        }
        cout << ans << '\n';
    }


    return 0;
}
