#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string.h>
using namespace std;

int d[1005][11];

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int j = 0; j < 10; j++) d[1][j] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= j; k++) {
                d[i][j] += d[i - 1][k];
                d[i][j] %= 10007;
            }
                

    int sum = 0;
    for (int j = 0; j <= 9; j++) sum += d[n][j];
    sum %= 10007;
    cout << sum << '\n';

    return 0;
}
