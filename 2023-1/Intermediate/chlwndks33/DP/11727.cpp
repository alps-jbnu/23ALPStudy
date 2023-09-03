// Baekjoon - 11727번 2*n 타일링2

#include <iostream>
using namespace std;

int d[1001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    if(n==1 || n==2 ) {
        cout << d[n];
        return 0;
    }
    for(int i=3; i<=n; i++) {
        d[i] = (d[i-1] + 2*d[i-2]) % 10007;
    }
    cout << d[n];
    
}