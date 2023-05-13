#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f; // 무한

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, arr[105][105], nxt[105][105], item[105];
    cin >> n >> m >> r;

    for(int i=1; i<=n; i++){
        fill(arr[i],arr[i]+1+n, INF);
    }
    
    for(int i=1; i<=n; i++) cin >> item[i];

    //step 1. 채울 수 있는 것 모두 채우기
    for(int i=1; i<=r; i++){
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

    bool visit[105];
    int ans=0;
    for(int i=1; i<=n; i++){
       fill(visit+1, visit+n+1,0);
       int tmp = 0;
       
       for(int j=1; j<=n; j++){
        if(arr[i][j] > m) continue;
        
        int cur = i;
        while(cur != j){
            visit[cur] = 1;
            cur = nxt[cur][j];
        }
        visit[j] = 1;
       }
       
       for(int j=1; j<=n; j++){
        if(visit[j]) tmp += item[j];
       }
       ans = max(ans,tmp);
    }
    cout << ans;
}
