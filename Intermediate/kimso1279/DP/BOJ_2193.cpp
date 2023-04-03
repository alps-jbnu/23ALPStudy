#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);

    int n;
    long long d[10000]; //오답이유 => 피보나치로 일반항이 지수항, 즉 조금만 커져도 숫자가 엄청나게 커짐

    cin >> n;
    
    // 초기값 정하기
    d[1] = 1;
    d[2] = 1;

    for(int i=3; i<=n; i++){
        //점화식
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[n] << "\n";
}
