#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
int s = 0;

void re(int a,int b,int n) {
    if (a==c&&b==r) {
        cout << s << "\n";
        return;
    }
    else if (c < a + n && r < b + n && c >= a && r >= b) {
        re(a, b, n / 2);
        re(a + n / 2, b, n / 2);
        re(a, b + n / 2, n / 2);
        re(a + n / 2, b + n / 2, n / 2);
    }
    else {
        s += n * n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> r >> c;
    re(0, 0, pow(2, n));
}
