#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int n, a[100001], d[100001];

    cin >> n;    
    for(int i=0; i<n; i++) cin >> a[i];

    d[0] = a[0];
    for(int i=1; i<n; i++){
        //점화식
        d[i] = max(a[i], d[i-1]+a[i]);
    }
    
    sort(d, d+n); // 최대값 구하기 위해 sort
    cout << d[n-1] << "\n";
}
