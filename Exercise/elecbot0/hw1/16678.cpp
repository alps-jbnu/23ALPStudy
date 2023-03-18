#include <bits/stdc++.h>

using namespace std;

int N;
long long a[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    long long hacker = a[0] - 1;
    a[0] = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] - a[i - 1] > 1) {
            hacker += a[i] - a[i - 1] - 1;
            a[i] = a[i - 1] + 1;
        }
    }
    cout << hacker;
    return 0;
}
