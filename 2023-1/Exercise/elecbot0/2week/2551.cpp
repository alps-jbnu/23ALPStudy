#include <bits/stdc++.h>

using namespace std;

int N;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        arr[num] += 1;
    }
    int ans1, ans2;
    long long min1 = LONG_LONG_MAX, min2 = LONG_LONG_MAX;
    for (int i = 1; i <= 10000; i++) {
        long long cal1 = 0, cal2 = 0;
        for (int j = 1; j <= 10000; j++) {
            cal1 += 1LL * arr[j] * abs(i - j);
            cal2 += 1LL * arr[j] * abs(i - j) * abs(i - j);
        }
        if (min1 > cal1) {
            ans1 = i;
            min1 = cal1;
        }
        if (min2 > cal2) {
            ans2 = i;
            min2 = cal2;
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
