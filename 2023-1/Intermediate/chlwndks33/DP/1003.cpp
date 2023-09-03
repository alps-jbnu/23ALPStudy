// Baekjoon - 1003번 피보나치 함수

#include <iostream>
using namespace std;

int d[41][2];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;
    for(int i = 2; i<=40; i++) {
        d[i][0] = d[i-2][0] + d[i-1][0];
        d[i][1] = d[i-2][1] + d[i-1][1];
    }
    while(n--) {
        int a;
        cin >> a;
        cout << d[a][0] << ' ' << d[a][1]<< '\n';
    }

}