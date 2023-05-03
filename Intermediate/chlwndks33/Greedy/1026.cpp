// 재배열 부등식 큰거끼리 곱하면 최대값 큰거랑 작은거랑 곱하면 최솟값

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[101], b[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int ans = 0;
    for(int i=0; i<n; i++)
        ans += a[i] * b[n-1-i];
    cout << ans;
}