#include <bits/stdc++.h>

using namespace std;

int field[203][203];
int visK[203][203];  // count of monkey's horse_move + 1 (cntK + 1)
int dx[12] = {1,-1, 0, 0, 2, 1,-1,-2,-2,-1, 1, 2};
int dy[12] = {0, 0, 1,-1, 1, 2, 2, 1,-1,-2,-2,-1};

int trip_bfs(int K, int W, int H){
    queue<pair<int,int>> q;
    queue<int> qK;  // count of monkey's horse_move (cntK)

    pair<int,int> cur = {0,0};
    int nxt_x,nxt_y;
    int cntK = 0;
    int move = 0;

    q.push(cur); qK.push(cntK);
    visK[cur.first][cur.second] = cntK+1;

    int size = q.size();

    while (!q.empty()){
        cur = q.front(); q.pop();
        cntK = qK.front(); qK.pop();
        size--;

        if (cur.first == H-1 && cur.second == W-1){
            return move;
        }

        for (int i=0;i<12;i++){
            if (i >= 4 && cntK >= K){
                break;
            }

            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < H && 0 <= nxt_y && nxt_y < W && field[nxt_x][nxt_y] == 0){
                if (i < 4 && (visK[nxt_x][nxt_y] == 0 || visK[nxt_x][nxt_y] > cntK+1)){
                    q.push(make_pair(nxt_x,nxt_y)); qK.push(cntK);
                    visK[nxt_x][nxt_y] = cntK+1;
                }
                else if (i >= 4 && (visK[nxt_x][nxt_y] == 0 || visK[nxt_x][nxt_y] > cntK+2)){
                    q.push(make_pair(nxt_x,nxt_y)); qK.push(cntK+1);
                    visK[nxt_x][nxt_y] = cntK+2;
                }
            }
        }

        if (size == 0){
            size = q.size();
            move++;
        }
    }

    return -1;  // cannot reach goal
}

int main(){
    ios::sync_with_stdio(0); cin.tie();

    int K,W,H;

    cin >> K;
    cin >> W >> H;

    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cin >> field[i][j];
        }
    }

    cout << trip_bfs(K,W,H);

    return 0;
}
