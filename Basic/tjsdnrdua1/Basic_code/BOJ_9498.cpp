#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr
    
    int jumsu;
    cin >> jumsu;

    if (90 <= jumsu && jumsu <= 100) cout << "A";
    else if (80 <= jumsu && jumsu < 90) cout << "B";
    else if (70 <= jumsu && jumsu < 80) cout << "C";
    else if (60 <= jumsu && jumsu < 70) cout << "D";
    else cout << "F";
}
