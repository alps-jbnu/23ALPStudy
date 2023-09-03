// Baekjoon - 2579번 계단오르기

#include <iostream>
using namespace std;

int k[301];
int arr[301][3];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n;
    for(int i=1; i<=n; i++)
        cin >> k[i];
    if(n==1) {
        cout << k[1];
        return 0;
    }
    arr[1][1] = k[1];
    arr[1][2] = 0;
    arr[2][1] = k[2];
    arr[2][2] = k[1] + k[2];
    for(int i=3; i<=n; i++) {
        arr[i][1] = max(arr[i-2][1], arr[i-2][2]) + k[i];
        arr[i][2] = arr[i-1][1] + k[i];
    }
    cout << max(arr[n][1], arr[n][2]);

}