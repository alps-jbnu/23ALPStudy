#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr
    
    int y;
    cin >> y;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        cout << 1;
    else cout << 0;
}
