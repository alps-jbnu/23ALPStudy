#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int p[n];
    for(int i=0; i<n; i++) cin >> p[i];
    sort(p,p+n);

    int sum = 0, before = 0;
    for(int i=0; i<n; i++){
        int now = p[i] + before;
        sum += now;
        before += p[i];
    }

    cout << sum;
}
