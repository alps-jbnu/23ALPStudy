// Baekjoon - 2193번 이친수  

#include <iostream>
using namespace std;

long long d[91][2];  //int로 선언해서 틀렸음
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n;
    d[1][0] = 0;
    d[1][1] = 1;
    if(n==1) {
        cout << d[n][0] + d[n][1];
        return 0;
    }
    for(int i=2; i<=n; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    cout << d[n][0] + d[n][1];
}