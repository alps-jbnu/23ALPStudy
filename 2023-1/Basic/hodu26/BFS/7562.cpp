#include <bits/stdc++.h>

using namespace std;

int board[303][303];
bool vis[303][303];
int dx[8] = {2, 1,-1,-2,-2,-1, 1, 2};
int dy[8] = {1, 2, 2, 1,-1,-2,-2,-1};

int chess_bfs(int l, pair<int,int> cur, pair<int,int> flag){
    queue<pair<int,int>> q;

    int nxt_x,nxt_y;
    int move = 0;

    q.push(cur);
    vis[cur.first][cur.second] = 1;

    int size = q.size();

    while (!q.empty()){
        cur = q.front(); q.pop();
        size--;

        if (cur == flag){
            return move;
        }

        for (int i=0;i<8;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < l && 0 <= nxt_y && nxt_y < l && board[nxt_x][nxt_y] == 0 && !vis[nxt_x][nxt_y]){
                q.push(make_pair(nxt_x,nxt_y));
                vis[nxt_x][nxt_y] = true;
            }
        }

        if (size == 0){
            size = q.size();
            move++;
        }
    }

    return move-1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T,l,Sx,Sy,Fx,Fy;

    cin >> T;

    while (T--){
        cin >> l;
        cin >> Sx >> Sy;
        cin >> Fx >> Fy;

        cout << chess_bfs(l,{Sx,Sy},{Fx,Fy}) << '\n';

        for (int i=0;i<l;i++){     // reset board & vis
            for (int j=0;j<l;j++){
                board[i][j] = 0;
                vis[i][j] = false;
            }
        }
    }

    return 0;
}
