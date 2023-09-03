#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string.h>
using namespace std;

int d[45];
int n, m, s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;


    d[0] = 1;  d[1] = 1; d[2] = 2;
    for (int i = 3; i <= n; i++)
        d[i] = d[i - 1] + d[i - 2];

    int index = 1;
    int ans = 1;
    for (int i = 0; i < m; i++) {
        cin >> s;
        ans *= d[s - index];
        index = s + 1;
    }

    ans *= d[n + 1 - index];

    cout << ans << '\n';


    return 0;
}
