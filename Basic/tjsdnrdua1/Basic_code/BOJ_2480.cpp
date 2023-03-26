#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr

    int x, y, z;
    cin >> x >> y >> z;
    if (x == y && y == z)
        cout << 10000 + (x * 1000);
    else if (x == y && y != z)
        cout << 1000 + (x * 100);
    else if (x != y && y == z)
        cout << 1000 + (y * 100);
    else if (x == z && x != y)
        cout << 1000 + (z * 100);
    else
        cout << max({ x, y, z }) * 100; //std::max Defined in <algorithm> initializer list
}
