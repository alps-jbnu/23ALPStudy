// Baekjoon - 10844번 쉬운 계단수

#include <iostream>
using namespace std;

int n;
long long d[101][10];
long long mod = 1000000000;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<10; i++) {
        d[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            if(j==0) {
                d[i][j] = d[i-1][j+1] % mod;
            }
            else if(j==9) {
                d[i][j] = d[i-1][j-1] % mod;
            }
            else {
                d[i][j] = (d[i-1][j-1]+ d[i-1][j+1]) % mod;
            }
        }
    }
    long long sum =0;
    for(int i=0; i<10; i++) {
        sum += d[n][i];
    }
    cout << sum % mod;
}