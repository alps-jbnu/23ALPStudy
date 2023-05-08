#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

string maze[1003];
int vis[1003][1003];  // J_vis = 1, F_vis = 2
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> J_q;
queue<pair<int,int>> F_q;

int run_bfs(int R, int C){
    pair<int,int> cur_loc,nxt_loc;
    int move = 1;

    int Jsize,Fsize;

    while(!J_q.empty()){
        Jsize = J_q.size();
        Fsize = F_q.size();

        while (!F_q.empty() && Fsize--){
            cur_loc = F_q.front(); F_q.pop();

            for (int i=0;i<4;i++){
                nxt_loc = make_pair(cur_loc.Y+dy[i],cur_loc.X+dx[i]);

                if (0 <= nxt_loc.Y && nxt_loc.Y < R && 0 <= nxt_loc.X && nxt_loc.X < C && maze[nxt_loc.Y][nxt_loc.X] != '#' && vis[nxt_loc.Y][nxt_loc.X] != 2){
                    F_q.push(nxt_loc);
                    vis[nxt_loc.Y][nxt_loc.X] = 2;
                }
            }
        }

        while (Jsize--){
            cur_loc = J_q.front(); J_q.pop();

            for (int i=0;i<4;i++){
                nxt_loc = make_pair(cur_loc.Y+dy[i],cur_loc.X+dx[i]);

                if (0 > nxt_loc.Y || nxt_loc.Y == R || 0 > nxt_loc.X || nxt_loc.X == C){
                    return move;
                }

                if (0 <= nxt_loc.Y && nxt_loc.Y < R && 0 <= nxt_loc.X && nxt_loc.X < C && maze[nxt_loc.Y][nxt_loc.X] == '.' && vis[nxt_loc.Y][nxt_loc.X] == 0){
                    J_q.push(nxt_loc);
                    vis[nxt_loc.Y][nxt_loc.X] = 1;
                }
            }
        }
        move++;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int R,C;

    cin >> R >> C;

    for (int i=0;i<R;i++){
        cin >> maze[i];

        for (int j=0;j<C;j++){
            if (maze[i][j] == 'J'){
                J_q.push(make_pair(i,j));
                vis[i][j] = 1;
            }

            if (maze[i][j] == 'F'){                      // F_num >= 1 .....
                F_q.push(make_pair(i,j));
                vis[i][j] = 2;
            }
        } 
    }

    int move = run_bfs(R,C);
    if (move == -1){
        cout << "IMPOSSIBLE";
    }
    else {
        cout << move;
    }

    return 0;
}
