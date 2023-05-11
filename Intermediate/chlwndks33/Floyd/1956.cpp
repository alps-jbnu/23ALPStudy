// baekjoon - 1956번 운동

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[401][401];
int n,m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        fill(d[i], d[i]+1+n, INF);
    while(m--) { //간선 입력 받기
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    for(int i=1; i<=n; i++) d[i][i] = 0; //자기 자신으로 가는 비용 0으로
    for(int k=1; k<=n; k++) { // 거쳐갈 정점 
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                 if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                 }
            }
        }
    }
    int ans = INF;
    for(int i=1; i<n; i++) {
        for(int j = i+1; j<=n; j++) {
            ans = min(d[i][j]+d[j][i],ans);                
        }
    }
    if(ans == INF) ans = -1;
    cout << ans;

}