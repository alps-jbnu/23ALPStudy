#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr

    int nat[5];
    int ave = 0;
    for (int i = 0; i < 5; i++) {
        cin >> nat[i];
        ave += nat[i];
    }
    ave /= 5;
    cout << ave << '\n';
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (nat[i] > nat[j]) {
                int temp = nat[i];
                nat[i] = nat[j];
                nat[j] = temp;
            }
        }
    }
    cout << nat[2];
}
