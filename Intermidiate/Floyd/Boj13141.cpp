#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int d[205][205];
tuple<int,int,int> edges[20005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n>>m;
    for(int i = 1;i<=n; i++)
        fill(d[i],d[i]+n+1,INF);
    for(int i =1; i<=n; i++)
        d[i][i]=0;
    for(int i = 0; i<m; i++){
        int s,e,l;
        cin >> s >> e >> l;
        d[s][e] = min(d[s][e],l);
        d[e][s] = min(d[e][s],l);
        edges[i] = {s,e,l};
    }
    for(int k = 1;k<=n; k++){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    double ans = INF;
    for(int i =1; i<=n; i++){
        double total = 0;
        for(int j = 0; j<m; j++){
            int s,e,l;
            tie(s,e,l) = edges[j];
            total = max(total,(double)(l+d[i][s] + d[i][e])/2);
        }
        ans = min(ans, total);
    }
    cout << fixed;
    cout.precision(1);
    cout << ans;
}
