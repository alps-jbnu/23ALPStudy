#include <bits/stdc++.h>

using namespace std;

int box[103][103][103];
bool vis[103][103][103];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<int> qx;
queue<int> qy;
queue<int> qz;

int tomato_bfs(int M, int N, int H){
    int cur_x,cur_y,cur_z;
    int nxt_x,nxt_y,nxt_z;
    int days = 0;

    int size = qx.size();

    while (!qx.empty()){
        cur_x = qx.front(); qx.pop();
        cur_y = qy.front(); qy.pop();
        cur_z = qz.front(); qz.pop();
        size--;

        for (int i=0;i<6;i++){
            nxt_x = cur_x + dx[i];
            nxt_y = cur_y + dy[i];
            nxt_z = cur_z + dz[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < M && 0 <= nxt_z && nxt_z < H && box[nxt_z][nxt_x][nxt_y] == 0 && !vis[nxt_z][nxt_x][nxt_y]){
                qx.push(nxt_x); qy.push(nxt_y); qz.push(nxt_z);
                vis[nxt_z][nxt_x][nxt_y] = true;
            }
        }

        if (size == 0){
            size = qx.size();
            days++;
        }
    }

    return days-1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int M,N,H;

    cin >> M >> N >> H;

    for (int i=0;i<H;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<M;k++){
                cin >> box[i][j][k];

                if (box[i][j][k] == 1){
                    qx.push(j); qy.push(k); qz.push(i);
                    vis[i][j][k] = true;
                }

                if (box[i][j][k] == -1){
                    vis[i][j][k] = true;
                }
            }
        }
    }

    int days = tomato_bfs(M,N,H);

    for (int i=0;i<H;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<M;k++){
                if (!vis[i][j][k]){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << days;

    return 0;
}
