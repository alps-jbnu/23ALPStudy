// Baekjoon - 11501번 주식

#include <iostream>
using namespace std;

int arr[1000001];
int t;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        fill(arr,arr+n,0);
        cin >> n;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int maxcost = arr[n-1];
        for(int i=n-2; i>=0; i--) {
            if(arr[i] < maxcost) { // 주식을 산다
                sum += maxcost-arr[i];
            }
            else if(arr[i] > maxcost) { // 가장 비싼 값 교체
                maxcost = max(maxcost,arr[i]);
            }
        }
        cout << sum << '\n';
    }
}