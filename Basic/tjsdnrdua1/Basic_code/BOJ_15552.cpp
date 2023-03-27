#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);        //false
    cin.tie(NULL);                     //nullptr
    
    int N, a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}
