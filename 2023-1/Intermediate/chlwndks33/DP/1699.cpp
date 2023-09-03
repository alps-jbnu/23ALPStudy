// Baekjoon - 1699번 제곱수의 합

#include <iostream>
using namespace std;

int n;
int d[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)  {
        d[i] = i;
        for(int j=1; j*j<=i; j++) {
            d[i] = min(d[i],d[i-j*j]+1);
        }
    }
    cout << d[n];
}