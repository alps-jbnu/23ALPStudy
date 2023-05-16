#include <bits/stdc++.h>

using namespace std;

int board[103][103];
int vis[103][103];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int blank_bfs(int M, int N, pair<int,int> cur){
    queue<pair<int,int>> q;

    q.push(cur);
    vis[cur.second][cur.first] = true;

    int nxt_x,nxt_y;
    int blank = 1;

    while (!q.empty()){
        cur = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < M && board[nxt_y][nxt_x] == 0 && !vis[nxt_y][nxt_x]){
                q.push(make_pair(nxt_x,nxt_y));
                vis[nxt_y][nxt_x] = true;
                blank++;
            }
        }
    }

    return blank;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int M,N,K,Sx,Sy,Fx,Fy;
    vector<int> blank;

    cin >> M >> N >> K;

    while(K--){
        cin >> Sx >> Sy >> Fx >> Fy;

        for (int i=Sy;i<Fy;i++){
            for (int j=Sx;j<Fx;j++){
                board[i][j] = 1;
            }
        }
    }

    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            if (board[i][j] == 0 && !vis[i][j]){
                blank.push_back(blank_bfs(M,N,{j,i}));
            }
        }
    }

    sort(blank.begin(),blank.end());

    int blanks = blank.size();

    cout << blanks << '\n';
    for (int i=0;i<blanks;i++){
        cout << blank[i] << ' ';
    }

    return 0;
}
