#include <bits/stdc++.h>

using namespace std;

int field[53][53];
bool vis[53][53];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int>> q;

void veg_bfs(int N, int M){
    pair<int,int> cur;
    int nxt_x,nxt_y;

    while (!q.empty()){
        cur = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < M && field[nxt_x][nxt_y] == 1 && !vis[nxt_x][nxt_y]){
                q.push(make_pair(nxt_x,nxt_y));
                vis[nxt_x][nxt_y] = true;
            }
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T,N,M,K,x,y, warms = 0;

    cin >> T;

    while (T--){
        cin >> N >> M >> K;

        for (int i=0;i<K;i++){
            cin >> x >> y;

            field[x][y] = 1;
        }

        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (!vis[i][j] && field[i][j] == 1){
                    q.push(make_pair(i,j));
                    vis[i][j] = true;
                    veg_bfs(N,M);
                    warms++;
                }
            }
        }

        cout << warms << '\n';

        warms = 0;
        for (int i=0;i<N;i++){      // 케이스마다 초기화해야함
            for (int j=0;j<M;j++){
                field[i][j] = 0;
                vis[i][j] = false;
            }
        }
        
    }

    return 0;
}
