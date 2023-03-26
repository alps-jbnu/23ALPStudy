// Baekjoon - 1932번 정수 삼각형

#include <iostream>
#include <algorithm>
using namespace std;

long long d[501][501];
int arr[501][501];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    d[1][1] = arr[1][1];
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(j==1) { 
                d[i][j] = d[i-1][j] + arr[i][j];
            }
            else if(j==i) {
                d[i][j] = d[i-1][j-1] + arr[i][j];
            }
            else {
                d[i][j] = max(d[i-1][j-1],d[i-1][j]) + arr[i][j];
            }
        }
    }
    cout << *max_element(d[n],d[n]+n+1);  //처음에 (d[n] , d[n] + n)  사이에서 최댓값을 찾아서 틀렸음 d[n][0] ~ d[n][n-1] x   ~d[n][n]까지 탐색해줘야함

}