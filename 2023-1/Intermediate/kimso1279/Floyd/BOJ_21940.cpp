#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f; // 무한

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, f, arr[205][205], c[205];
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        fill(arr[i],arr[i]+1+n, INF);
    }

    //step 1. 채울 수 있는 것 모두 채우기
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = min(arr[a][b], c);
    }
    cin >> f;
    for(int i=1; i<=f; i++) cin >> c[i];

    for(int i=1; i<=n; i++)
        arr[i][i] = 0;

    //step 2 ~ n
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][k] > arr[j][i] + arr[i][k]){
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }
    
    vector<pair<int,int>> v;
    for(int i=1; i<=n; i++){
        int mx = 0;
        for(int j=1; j<=f; j++){
            mx = max(mx, arr[i][c[j]] + arr[c[j]][i]);
        }
        v.push_back({mx, i});
    }
    sort(v.begin(), v.end());

    for(auto x : v){
        if(v[0].first < x.first) break;
        cout << x.second << " ";
    }
}
