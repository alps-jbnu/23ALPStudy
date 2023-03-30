#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string.h>
using namespace std;

int a[10005];
int d[10005];
int n, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    d[0] = 1;
    for (int i = 0; i < n; i++) 
        for (int j = a[i]; j <= k; j++) 
            d[j] += d[j - a[i]];
        
    cout << d[k] << '\n';

    return 0;
}
