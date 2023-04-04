#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr
    
    int i = 0;
    while (i < 3) {
        bool yut[4];
        for (int i = 0; i < 4; i++) {
            cin >> yut[i];
        }
        int sum = yut[0] + yut[1] + yut[2] + yut[3];
        if (sum == 0) cout << "D\n";
        else if (sum == 1) cout << "C\n";
        else if (sum == 2) cout << "B\n";
        else if (sum == 3) cout << "A\n";
        else if (sum == 4) cout << "E\n";
        i++;
    }
}
