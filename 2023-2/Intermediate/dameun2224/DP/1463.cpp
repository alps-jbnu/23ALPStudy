#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n;
int d[1000005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (i % 3 == 0) a = d[i / 3] + 1;
        if (i % 2 == 0) b = d[i / 2] + 1;
        c = d[i - 1] + 1;
        d[i] = min(a, min(b, c));
    }

    cout << d[n] << '\n';

    return 0;
}
