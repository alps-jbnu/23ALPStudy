// Baekjoon - 9084번 동전

#include <iostream>
using namespace std;

int n,m;
int a[10005], d[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        fill(d, d+ 10005, 0);
        cin >> n;
        for(int i=0; i<n; i++) 
            cin >> a[i];
        cin >> m;
        d[0]= 1;
        for(int i=0; i < n; i++)
            for(int j=a[i]; j<=m; j++)
                d[j] += d[j - a[i]];
        cout << d[m] << '\n';
    }
}
