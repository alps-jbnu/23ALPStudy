#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr

    long long A, B;
    cin >> A >> B;
    if (A > B) {
        long long temp = A;
        A = B;
        B = temp;
    }
    if (A == B || B - A == 1) cout << 0;
    else {
        cout << B - A - 1 << '\n';
        for (long long i = A + 1; i < B; i++) {
            cout << i << " ";
        }
    }
}
