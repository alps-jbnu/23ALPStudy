#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);        //false
    cin.tie(NULL);                     //nullptr
    
    int N;
    cin >> N;
    for (int i = 0; i < 2 * N - 1; i++) {
        if (i < N) {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int J = 0; J < 2 * (N - i) - 1; J++)
                cout << "*";
            cout << '\n';
        }
        else {
            for (int k = 0; k < (2 * N - 1) - i - 1; k++)
                cout << " ";
            for (int K = 0; K < 2 * i - (2 * (N - 1) - 1); K++)
                cout << "*";
            cout << '\n';
        }
    }
}
