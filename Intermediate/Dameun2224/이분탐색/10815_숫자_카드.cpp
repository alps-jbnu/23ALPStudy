#include <iostream>
#include <algorithm>
using namespace std;

int a[500005];

int binarySearch(int n, int t) {
    int st = 0;
    int en = n - 1;

    while (st <= en) {
        int mid = (st + en) / 2;
        if (a[mid] < t) st = mid + 1;
        else if (a[mid] > t) en = mid - 1;
        else if (a[mid] == t) return 1;
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << binarySearch(n, x) << ' ';
    }

    return 0;
}
