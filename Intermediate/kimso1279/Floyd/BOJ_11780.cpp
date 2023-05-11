#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f; // 무한

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, arr[105][105], nxt[105][105];
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        fill(arr[i],arr[i]+1+n, INF);
    }
    //step 1. 채울 수 있는 것 모두 채우기
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = min(arr[a][b],c);
        nxt[a][b] = b;
    }
    for(int i=1; i<=n; i++)
        arr[i][i] = 0;

    //step 2 ~ n
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][k] > arr[j][i] + arr[i][k]){
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    //출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == INF) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    //경로 복원
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == 0 || arr[i][j] == INF){
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << " ";
            for(auto x : path) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
