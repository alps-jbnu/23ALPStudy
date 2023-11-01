#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n;
int t[20], p[20], d[20];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];

    // i = n부터 1까지 1씩 줄이면서 진행되므로
    // d[1]이 최대값?
    for (int i = n; i >= 1; i--) {
        // i일에 상담을 할 수 있는 경우
        if (i + t[i] - 1 <= n) d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
        // i일에 상담을 할 수 없는 경우
        else d[i] = d[i + 1];
    }

    cout << *max_element(d, d + n + 1);

    return 0;
}
