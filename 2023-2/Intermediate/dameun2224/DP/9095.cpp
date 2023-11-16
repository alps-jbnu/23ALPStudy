#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n, m;
int d[15];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1; d[2] = 2; d[3] = 4;
    for (int i = 4; i < 12; i++)
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    
    cin >> n;
    while (n--) {
        cin >> m;
        cout << d[m] << '\n';
    }

    return 0;
}
