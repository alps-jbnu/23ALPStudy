// baekjoon - 14938번 서강그라운드

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int region[101];
int d[101][101];
int n,m,r,ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) { //아이템 수 입력
        cin >> region[i];
        fill(d[i], d[i]+n+1 , INF);
        d[i][i] = 0;
    }
    while(r--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b],c);
        d[b][a] = min(d[b][a],c);
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(d[i][j] > d[i][k]+d[k][j]) {
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=1; j<=n; j++) {
            if(d[i][j] == INF) continue;
            if(d[i][j] > m) continue;
            sum += region[j];
        }
        ans = max(sum,ans);
    }
    cout << ans;
    
}