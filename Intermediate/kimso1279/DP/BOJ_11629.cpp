#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int n, m;

    cin >> n >> m;
    int d[100004], a[1000004];

    d[0] = 0;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = d[i-1] + a[i];
    }
    
    while(m--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }
}
