#include <bits/stdc++.h>

using namespace std;

string place[1003];
int vis[1003][1003];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

queue<pair<int,int>> qS;  // Sangeun
queue<pair<int,int>> qF;  // Fire

int run_bfs(int w, int h){
    pair<int,int> cur;
    int nxt_x,nxt_y;
    int time = 0;

    int sizeS = qS.size();
    int sizeF = qF.size();

    while (!qS.empty()){
        while (!qF.empty() && sizeF != 0){  // Fire
            cur = qF.front(); qF.pop();
            sizeF--;

            for (int i=0;i<4;i++){
                nxt_x = cur.first + dx[i];
                nxt_y = cur.second + dy[i];

                if (0 <= nxt_x && nxt_x < h && 0 <= nxt_y && nxt_y < w && place[nxt_x][nxt_y] != '#' && vis[nxt_x][nxt_y] != 2){
                    qF.push(make_pair(nxt_x,nxt_y));
                    vis[nxt_x][nxt_y] = 2;
                }
            }
        }

        while (sizeS != 0){                // Sangeun
            cur = qS.front(); qS.pop();
            sizeS--;

            if (cur.first == 0 || cur.first == h-1 || cur.second == 0 || cur.second == w-1){
                return time+1;
            }

            for (int i=0;i<4;i++){
                nxt_x = cur.first + dx[i];
                nxt_y = cur.second + dy[i];

                if (0 <= nxt_x && nxt_x < h && 0 <= nxt_y && nxt_y < w && place[nxt_x][nxt_y] == '.' && vis[nxt_x][nxt_y] == 0){
                    qS.push(make_pair(nxt_x,nxt_y));
                    vis[nxt_x][nxt_y] = 1;
                }
            }
        }
        sizeS = qS.size();
        sizeF = qF.size();
        time++;
    }

    return -1;  // IMPOSSIBLE
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T,w,h, time;

    cin >> T;

    while (T--){
        cin >> w >> h;

        for (int i=0;i<h;i++){
            cin >> place[i];

            for (int j=0;j<w;j++){
                if (place[i][j] == '@'){
                    qS.push(make_pair(i,j));
                    vis[i][j] = 1;
                }

                if (place[i][j] == '*'){
                    qF.push(make_pair(i,j));
                    vis[i][j] = 2;
                }
            }
        }

        time = run_bfs(w,h);

        if (time == -1){
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << time << '\n';
        }

        for (int i=0;i<h;i++){     // reset board & vis
            for (int j=0;j<w;j++){
                place[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        while (!qS.empty()){ qS.pop(); }  // reset qS
        while (!qF.empty()){ qF.pop(); }  // reset qF
    }

    return 0;
}
