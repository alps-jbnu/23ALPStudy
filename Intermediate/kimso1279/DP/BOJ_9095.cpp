#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int n, d[20];

    d[1] = 1, d[2] = 2, d[3]=4; // 초기값
    for(int i=4; i < 11; i++){
        d[i] = d[i-1]+d[i-2]+d[i-3];  // 점화식
    }
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << d[n] << "\n";
    }
}
