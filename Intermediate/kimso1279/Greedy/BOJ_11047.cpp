#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k, cnt=0;
    cin >> n >> k;

    int A[1000001];
    for(int i=0; i<n; i++) cin >> A[i];

    for(int i=n-1; i>=0; i--){
        cnt += k / A[i]; // 나눈 몫 저장
        k %= A[i]; // 나머지 저장
    }

    cout << cnt;
}
