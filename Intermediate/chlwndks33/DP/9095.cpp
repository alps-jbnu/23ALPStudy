// Baek joon - 1,2,3 더하기

#include <iostream>
using namespace std;

int arr[12];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4; i<=12; i++) {
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
    }
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        cout << arr[a] << '\n';
    }
}