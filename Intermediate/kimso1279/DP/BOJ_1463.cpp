#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int n, d[1000005];
    cin >> n;

    d[1] = 0; // 초기값
    for(int i=2; i <= n; i++){
        d[i] = d[i-1]+1; //1을 빼거나
        if(i%2 == 0) d[i] = min(d[i], d[i/2]+1); // 2로 나누거나
        if(i%3 == 0) d[i] = min(d[i], d[i/3]+1); // 3으로 나누거나
    }

    cout << d[n];
}
