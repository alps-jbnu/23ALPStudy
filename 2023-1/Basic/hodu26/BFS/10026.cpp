#include <bits/stdc++.h>

using namespace std;

string field[103];
int vis[103][103];  // 0 -> not see / 1 -> xnor see / 2 -> nor,xnor see
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int>> q;

void rgb_bfs(int N, char color){
    pair<int,int> cur;
    int nxt_x,nxt_y;

    while (!q.empty()){
        cur = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < N && vis[nxt_x][nxt_y] != 2){
                if (field[nxt_x][nxt_y] == color && vis[cur.first][cur.second] == 2){   // normal
                    q.push(make_pair(nxt_x,nxt_y));
                    vis[nxt_x][nxt_y] = 2;
                } 
                else if ((color == 'R' || color == 'G') && (field[nxt_x][nxt_y] == 'R' || field[nxt_x][nxt_y] == 'G') && vis[nxt_x][nxt_y] == 0){  // not normal
                    q.push(make_pair(nxt_x,nxt_y));
                    vis[nxt_x][nxt_y] = 1;
                } 
            }
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, nor=0 , xnor=0;

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> field[i];
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (vis[i][j] != 2){  // normal people see X
                if (vis[i][j] == 0){
                    xnor++;
                }
                nor++;

                q.push(make_pair(i,j));
                vis[i][j] = 2;
                rgb_bfs(N,field[i][j]);
            }
        }
    }

    cout << nor << ' ' << xnor;

    return 0;
}
