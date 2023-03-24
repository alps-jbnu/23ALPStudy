#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);        //false
    cin.tie(NULL);                     //nullptr
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        for (int k = N - i - 1; k > 0; k--) {
            cout << " ";
        }
        for (int l = N - i - 1; l > 0; l--) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
    for (int I = N - 2; I >= 0; I--) {
        for (int j = 0; j <= I; j++) {
            cout << "*";
        }
        for (int k = N - I - 1; k > 0; k--) {
            cout << " ";
        }
        for (int l = N - I - 1; l > 0; l--) {
            cout << " ";
        }
        for (int j = 0; j <= I; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}
