#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f; // 무한

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, arr[205][205], nxt[205][205];
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        fill(arr[i],arr[i]+1+n, INF);
    }
    
    //step 1. 채울 수 있는 것 모두 채우기
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = c;
        arr[b][a] = c;
        nxt[a][b] = b;
        nxt[b][a] = a;
    }

    for(int i=1; i<=n; i++)
        arr[i][i] = 0;

    //step 2 ~ n
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][k] > arr[j][i] + arr[i][k]){
                    arr[j][k] = arr[j][i] + arr[i][k];
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) cout << "- ";
            else cout << nxt[i][j] << " ";
        }
        cout << "\n";
    }
}
