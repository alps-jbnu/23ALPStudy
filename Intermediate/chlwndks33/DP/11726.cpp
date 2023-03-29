// Baekjoon - 11762번 2*n 타일링

#include <iostream>
using namespace std;

int arr[10001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    arr[1] = 1;
    arr[2] = 2;
    cin  >> n;
    for(int i=3; i<=n; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }
    cout << arr[n];

}