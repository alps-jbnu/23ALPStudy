#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int w[n];
    for(int i=0; i<n; i++) cin >> w[i];
    sort(w, w+n);

    int ans=0;
    for(int i=1; i<=n; i++){
        ans = max(ans, w[n-i]*i);
    }
    cout << ans;
}
