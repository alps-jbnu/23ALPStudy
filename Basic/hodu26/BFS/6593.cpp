#include <bits/stdc++.h>

using namespace std;

char city[33][33][33];
bool vis[33][33][33];
int dx[6] = {0, 0, 1,-1, 0, 0};
int dy[6] = {1,-1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1,-1};

int escape_bfs(int L, int R, int C, int start[], int flag[]){  // start[3] = {x,y,z}, flag[3] = {x,y,z}
    queue<int> qx;
    queue<int> qy;
    queue<int> qz;

    int cur_x,cur_y,cur_z;
    int nxt_x,nxt_y,nxt_z;
    int time = 0;

    qx.push(start[0]);
    qy.push(start[1]);
    qz.push(start[2]);
    vis[start[2]][start[0]][start[1]] = true;

    int size = qx.size();

    while (!qx.empty()){
        cur_x = qx.front(); qx.pop();
        cur_y = qy.front(); qy.pop();
        cur_z = qz.front(); qz.pop();
        size--;

        if (cur_x == flag[0] && cur_y == flag[1] && cur_z == flag[2]){
            return time;  // Escape!
        }

        for (int i=0;i<6;i++){
            nxt_x = cur_x + dx[i];
            nxt_y = cur_y + dy[i];
            nxt_z = cur_z + dz[i];

            if (0 <= nxt_x && nxt_x < R && 0 <= nxt_y && nxt_y < C && 0 <= nxt_z && nxt_z < L && city[nxt_z][nxt_x][nxt_y] != '#' && !vis[nxt_z][nxt_x][nxt_y]){
                qx.push(nxt_x); qy.push(nxt_y); qz.push(nxt_z);
                vis[nxt_z][nxt_x][nxt_y] = true;
            }
        }

        if (size == 0){
            size = qx.size();
            time++;
        }
    }

    return -1;  // Trapped!
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int L,R,C, time;
    int start[3];
    int flag[3];

    while (true){
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0){  // finish
            return 0;
        }

        for (int i=0;i<L;i++){
            for (int j=0;j<R;j++){
                for (int k=0;k<C;k++){
                    cin >> city[i][j][k];

                    if (city[i][j][k] == 'S'){
                        start[2] = i; start[0] = j; start[1] = k;
                    }

                    if (city[i][j][k] == 'E'){
                        flag[2] = i; flag[0] = j; flag[1] = k;
                    }
                }
            }
        }

        time = escape_bfs(L,R,C,start,flag);

        if (time == -1){
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << time << " minute(s).\n";
        }

        for (int i=0;i<L;i++){          // reset vis
            for (int j=0;j<R;j++){
                for (int k=0;k<C;k++){
                    vis[i][j][k] = false;
                }
            }
        }
    }

    return 0;
}
