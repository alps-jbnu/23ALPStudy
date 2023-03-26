// Baekjoon - 11055 가장 큰 증가하는 부분 수열

#include <iostream>
#include <algorithm>
using namespace std;

int d[1001];
int arr[1001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        d[i] = arr[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(d[i] > d[j]) {
                d[i] = max(d[i], d[j] + arr[i]);
            }
        }
    }
    cout << *max_element(d+1, d+n+1);

}
