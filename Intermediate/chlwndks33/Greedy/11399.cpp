// Baekjoon - 11399번 ATM

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr,arr+n);
    int sum = arr[0];
    for(int i=1; i<n; i++) {
        arr[i] = arr[i-1] + arr[i];
        sum += arr[i];
    }
    cout << sum;
}