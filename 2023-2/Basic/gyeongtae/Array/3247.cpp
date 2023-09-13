#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    int count = 0;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> c;
    sort(a, a + n);
    int i = 0, j = n-1;
    int p = 1;
    while (i<j) {
        if (a[i] + a[j] == c) {
            count++;
            i++;
            j--;
        }
        else if (a[i] + a[j] < c) {
            i++;
        }
        else {
            j--;
        }
        
        if (j > n) {
            j = n ;
        }
        //cout << i << " " << j << "\n";
    }
    cout << count;
    delete[] a;
    return 0;
}
