#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);        //false
    cin.tie(NULL);                     //nullptr
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-i-1; j++) {
            cout << " ";
        }
        for (int k = 0; k < 2 * (i+1) - 1; k++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j <= i; j++)
            cout << " ";
        for (int k = 0; k < 2 * (N - i - 1) - 1; k++) {
            cout << "*";
        }
        cout << '\n';
    }
}
