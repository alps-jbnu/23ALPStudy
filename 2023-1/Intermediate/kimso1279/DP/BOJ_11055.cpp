#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int n, a[100001], d[100001];

    cin >> n;    
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++) d[i] = a[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[i] > a[j]){
                //점화식
                d[i] = max(d[i], d[j]+a[i]);
            }
        }
    }
    
    sort(d, d+n+1); // 최대값 구하기 위해 sort
    cout << d[n] << "\n";
}
