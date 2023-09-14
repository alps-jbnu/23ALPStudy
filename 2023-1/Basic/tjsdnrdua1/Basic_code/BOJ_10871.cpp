#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr

    int N, X;
    cin >> N >> X;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input < X)
            cout << input << ' ';
    }
}
