// baekjoon - 1507번 궁금한 민호

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[21][21];
int ans[21][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> d[i][j];
            ans[i][j] = d[i][j];
        }
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if((i==k) || (j==k)) continue;
                else if(d[i][j] > d[i][k]+ d[k][j]) {
                    cout << -1;
                    return 0;
                }
                else if(d[i][j] == d[i][k] + d[k][j]) {
                    ans[i][j] = 0;
                }
            }
        }
    }
    int sum =0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sum+=ans[i][j];
        }
    }
    cout << sum/2;
}
