#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <limits.h>
using namespace std;

long long int t, n;
long long int a[1000005];
// n-1 인덱스부터,0까지 역순으로 진행
// 현재 mx보다 큰 수를 만나면 mx를 변경, 작거나 같다면 차이를 sum에 더함

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        long long int mx = 0;
        long long int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < mx) sum += mx - a[i];
            else if (a[i] == mx) continue;
            else if (a[i] > mx) mx = a[i];
        }
        cout << sum << '\n';
    }

    return 0;
}
