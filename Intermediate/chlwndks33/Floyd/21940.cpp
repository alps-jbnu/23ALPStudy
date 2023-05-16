// baekjoon - 21940번 가운데에서 만나기

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int INF = 0x3f3f3f3f;
int n,m,num;
int d[201][201];
int region[201];
vector<pair<int,int>> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        fill(d[i], d[i]+n+1, INF);
    for(int i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    cin >> num;
    for(int i=1; i<=num; i++) {
        cin >> region[i];
    }
    for(int i=1; i<=n; i++)
        d[i][i] = 0;
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(d[i][j] > d[i][k]+d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=1; j<=num; j++) {
            sum = max(d[region[j]][i] + d[i][region[j]],sum);
        }
        vec.push_back({sum,i});
    }
    sort(vec.begin(),vec.end());
    int start = vec[0].first;
    for(auto cur : vec) {
        if(start < cur.first) break;
        cout << cur.second << " ";
    }

}