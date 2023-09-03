#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);        //false
    cin.tie(0);                     //nullptr
    
    int ar[3];
    for (int i = 0; i < 3; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = i+1; j < 3; j++) {
            if (ar[i] > ar[j]) {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }   //swap method
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << ar[i]<<' ';
    }
}
