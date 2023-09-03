#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int a[n], b[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];   
    sort(a,a+n);
    sort(b,b+n);

    int sum=0;
    for(int i=0; i<n; i++){ 
        sum += a[i] * b[n-1-i];
    }

    cout << sum;
}
